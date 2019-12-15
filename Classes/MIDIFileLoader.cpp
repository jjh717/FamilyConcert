/*
 *  MIDIFileLoader.cpp
 *  ofxMidiFileLoader
 *
 *  Created by Andrew on 20/11/2013.
 *  Copyright 2013 QMUL. All rights reserved.
 *
 */

#include "MIDIFileLoader.h"
#include "GameManager.h"

MIDIFileLoader:: MIDIFileLoader(){
	printMidiInfo = true;
}


int MIDIFileLoader::loadFile(std::string& filename){
    CCLOG("filename : %s",filename.c_str());
	
	pulsesPerQuarternote = 240;

	lastTick = 0;
	lastMillis = 0;
	
	beatPeriod = 60000000.0 / 120.0;
	beatPeriod = 500;///guessing
	printf("FIRST BEAT PERIOD %f\n", beatPeriod);
	//lastMeasurePosition = 0;
	/*
	noteOnIndex = 0;
	firstTickTime = 0;
	beatsPerMeasure = 4;
	numberOfBeatsAtLastPosition = 0;
	lastBeatPosition = 0;
	*/
	//setTempoFromMidiValue(500000, myMidiEvents);//default is 120bpm
	
	MIDIFileReader fr(filename);
	
	if (!fr.isOK()) {
		std::cerr << "Error: " << fr.getError().c_str() << std::endl;
		return 1;
	}
	
	MIDIComposition c = fr.load();
	
	switch (fr.getFormat()) {
		case MIDI_SINGLE_TRACK_FILE: std::cout << "Format: MIDI Single Track File" << std::endl; break;
		case MIDI_SIMULTANEOUS_TRACK_FILE: std::cout << "Format: MIDI Simultaneous Track File" << std::endl; break;
		case MIDI_SEQUENTIAL_TRACK_FILE: std::cout << "Format: MIDI Sequential Track File" << std::endl; break;
		default: std::cout << "Format: Unknown MIDI file format?" << std::endl; break;
	}
	
	std::cout << "Tracks: " << c.size() << std::endl;
	//Singleton<GameManager>::GetInst()->gameTotalTime.resize(c.size()-1);
	int td = fr.getTimingDivision();
	if (td < 32768) {
		if (printMidiInfo)
			std::cout << "Timing division: " << fr.getTimingDivision() << " ppq" << std::endl;
		
		pulsesPerQuarternote = fr.getTimingDivision();		
		
		//myMidiEvents.pulsesPerQuarternote = fr.getTimingDivision();
		//ticksPerMeasure = myMidiEvents.pulsesPerQuarternote * 4;//default setting
		
	} else {
		int frames = 256 - (td >> 8);
		int subframes = td & 0xff;
		if (printMidiInfo)
			std::cout << "SMPTE timing: " << frames << " fps, " << subframes << " subframes" << std::endl;
	}
	 
	for (MIDIComposition::const_iterator i = c.begin(); i != c.end(); ++i)
    {
		if (printMidiInfo)
			std::cout << "Start of track: " << i->first+1 << std::endl;
       // CCLog("tst1 : %d   %d",++tst1,c.size());
		
        for (MIDITrack::const_iterator j = i->second.begin(); j != i->second.end(); ++j)
        {
         	unsigned int t = j->getTime();
			int ch = j->getChannelNumber();
          
			if (j->isMeta())
            {
				int code = j->getMetaEventCode();
				std::string name;
				bool printable = true;
               
                switch (code)
                {
					case MIDI_END_OF_TRACK:
                    {
						std::cout << t << ": End of track" << std::endl;
                      
						break;
					}
					case MIDI_TEXT_EVENT: name = "Text"; break;
					case MIDI_COPYRIGHT_NOTICE: name = "Copyright"; break;
					case MIDI_TRACK_NAME: name = "Track name"; break;
					case MIDI_INSTRUMENT_NAME: name = "Instrument name"; break;
					case MIDI_LYRIC: name = "Lyric"; break;
					case MIDI_TEXT_MARKER: name = "Text marker"; break;
					case MIDI_SEQUENCE_NUMBER: name = "Sequence number"; printable = false; break;
					case MIDI_CHANNEL_PREFIX_OR_PORT: name = "Channel prefix or port"; printable = false; break;
					case MIDI_CUE_POINT: name = "Cue point"; break;
					case MIDI_CHANNEL_PREFIX: name = "Channel prefix"; printable = false; break;
					case MIDI_SEQUENCER_SPECIFIC: name = "Sequencer specific"; printable = false; break;
					case MIDI_SMPTE_OFFSET: name = "SMPTE offset"; printable = false; break;
						
					case MIDI_SET_TEMPO:
					{
						int m0 = j->getMetaMessage()[0];
						int m1 = j->getMetaMessage()[1];
						int m2 = j->getMetaMessage()[2];
						long tempo = (((m0 << 8) + m1) << 8) + m2;
						//if (printMidiInfo)
						std::cout << t << ": Tempo(period): " << 60000000.0 / double(tempo) << std::endl;
						std::cout << "tempo was " << tempo << std::endl;
						
						
						//Joel - this bit needs checking
						beatPeriod = 60000000.0 / double(tempo);
						printf("BPM??? %f\n", beatPeriod);
						//i think it needs to be period not tempo
						beatPeriod = 60000.0/beatPeriod;
						printf("beat period %f\n", beatPeriod);
						
					//	double tmp = updateElapsedTime(t);
						/*
						DoubleVector tmp;
						
						double lastTickInMillis = 0;
						double millisTimeNow = lastTickInMillis;
						int tickInterval = 0;
						if (myMidiEvents.periodValues.size() > 0){
							lastTickInMillis = myMidiEvents.periodValues[myMidiEvents.periodValues.size()-1][2];
							tickInterval = t  - myMidiEvents.periodValues[myMidiEvents.periodValues.size()-1][0];
							millisTimeNow = lastTickInMillis + (myMidiEvents.periodValues[myMidiEvents.periodValues.size()-1][1]*tickInterval);
							
						}
						
						tmp.push_back(t);
						
						
						tmp.push_back(60000000.0 / double(tempo));	
						double tmpTempoVal = 60000000.0 / double(tempo);
						tmp.push_back(millisTimeNow);
						
						myMidiEvents.periodValues.push_back(tmp);
						
						printf("tick[%i]: TEMPO %d tempoVal %f : time now %f\n", t, tempo, tmpTempoVal, millisTimeNow);
						*/
					}
						break;
						
					case MIDI_TIME_SIGNATURE:
					{
						int numerator = j->getMetaMessage()[0];
						int denominator = 1 << (int)j->getMetaMessage()[1];
						
						//newTimeSignature(t, numerator, denominator);
						
						//if (printMidiInfo)
						std::cout << t << ": Time signature: " << numerator << "/" << denominator << std::endl;
						printf(" ticks %i Time signature: %i by %i \n", t,  numerator , denominator );
					}
						
					case MIDI_KEY_SIGNATURE:
					{
						int accidentals = j->getMetaMessage()[0];
						int isMinor = j->getMetaMessage()[1];
						bool isSharp = accidentals < 0 ? false : true;
						accidentals = accidentals < 0 ? -accidentals : accidentals;
                        
                        
						if (printMidiInfo)
                        {
                          //  CCLog("accidentals : %d",accidentals);
                          //  CCLog("isMinor : %d",accidentals);
                          //  CCLog("isSharp : %d",isSharp);
                            

							std::cout << t << ": Key signature: " << accidentals << " "
							<< (isSharp ?
								(accidentals > 1 ? "sharps" : "sharp") :
								(accidentals > 1 ? "flats" : "flat"))
							<< (isMinor ? ", minor" : ", major") << std::endl;
                        }
					}
						
				}
				
				
				if (name != "") {
					if (printable) {
						std::cout << t << ": File meta event: code " << code
						<< ": " << name << ": \"" << j->getMetaMessage()
						<< "\"" << std::endl;
					} else {
						std::cout << t << ": File meta event: code " << code
						<< ": " << name << ": ";
						for (int k = 0; k < j->getMetaMessage().length(); ++k) {
							std::cout << (int)j->getMetaMessage()[k] << " ";
						}
					}
                    testCount = 0;
                    lastMillis = 0;
                    lastTick = 0;
				}
				continue;
			}
            
            
            
//			double newBeatLocation = 0;
			switch (j->getMessageType())
            {
				case MIDI_NOTE_ON:
                    /*
					if (printMidiInfo)
                    {
						std::cout << t << ": Note: channel " << ch
						<< " duration " << j->getDuration()
						<< " pitch " << j->getPitch()
						<< " velocity " << j->getVelocity() << std::endl;
//						<< "event time " << myMidiEvents.getEventTimeMillis(t) << std::endl;
					}
                     */
					noteData newNote;
					newNote.pitch = j->getPitch()-21;
					newNote.ticks = t;
					newNote.velocity = j->getVelocity();
					newNote.durationTicks = j->getDuration();
                    
					newNote.durationMillis = ticksToMillis(newNote.durationTicks);
                    /*
                    if(t < lastTick)
                    {
                        lastTick = 0;
                    }
                    */
                    /*
                    CCLog("lastTick : %d",lastTick);
                    CCLog("beatPeriod : %f",beatPeriod);
                    CCLog("pulsesPerQuarternote : %d",pulsesPerQuarternote);
                    CCLog("t : %d",t);
                     */
                    newNote.elapsedMillis = ((beatPeriod * ((int)t - lastTick)) / (double) pulsesPerQuarternote);//update time elapsed since we last updated
                 //   CCLog("beatPeriod : %f",newNote.elapsedMillis);
                    newNote.elapsedMillis /= 1000;
                    
                    
                    double millis;
                    if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
                    {
                        t = t*6;//용머리 가로길이
                    }

                  	millis = updateElapsedTime(t);
                    
					//millis = (beatPeriod * newNote.ticks / (double) pulsesPerQuarternote);
                    
                    
					newNote.timeMillis = millis;
                    
                    newNote.channel = ch;
                    midiEvents.push_back(newNote);
                    
					Singleton<GameManager>::GetInst()->gameTotalTime[ch] = millis/1000.0f;
                    
                   
                    if(Singleton<GameManager>::GetInst()->gameMode == NORMAL_GAME)
                    {
                        Singleton<GameManager>::GetInst()->makeCollisinoBoxes(newNote.pitch,newNote.durationMillis,newNote.durationTicks,fr.getTimingDivision(),ch,j->getVelocity(),newNote.elapsedMillis,newNote.timeMillis);
                        
                        
                    }
                    else if(Singleton<GameManager>::GetInst()->gameMode == SINGE_GAME)
                    {
                        Singleton<GameManager>::GetInst()->makeCollisinoBoxes(newNote.pitch,newNote.durationMillis,newNote.durationTicks,fr.getTimingDivision(),ch,j->getVelocity(),newNote.elapsedMillis,newNote.timeMillis);
                        
                        
                    }
                    else if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
                    {
                        Singleton<GameManager>::GetInst()->makeCollisinoBoxes(newNote.pitch,newNote.durationMillis,newNote.durationTicks,fr.getTimingDivision(),ch,j->getVelocity(),newNote.elapsedMillis,newNote.timeMillis);
                        Singleton<GameManager>::GetInst()->makeCollisinoBoxes_copy(newNote.pitch,newNote.durationMillis,newNote.durationTicks,fr.getTimingDivision(),ch,j->getVelocity(),newNote.elapsedMillis,newNote.timeMillis);
                    }
                    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                    CCLOG("testCount : %d, ch : %d,note : %d,velocity : %d, elapsedMillis : %f, durationTicks : %d, durationMillis : %f ,timeMillis : %f",testCount++,ch,newNote.pitch,newNote.velocity,newNote.elapsedMillis,newNote.durationTicks,newNote.durationMillis,newNote.timeMillis);
#endif
                    
                   
                    
                    
					//newBeatLocation = getBeatPositionForTickCount(t, myMidiEvents);
					
					//	printf("%i channel %i durn %i pitch %i vel %i event time %f beat pos %f\n", t, ch, (int)j->getDuration(), (int)j->getPitch(), (int)j->getVelocity(), myMidiEvents.getEventTimeMillis(t)
					//		   , newBeatLocation);
					
					
					
					//	printf("Beat location %3.2f\n", newBeatLocation);
					
				/*
					v.clear();
					
					//	printf("note on at %i\n", t);
					
					//if (!chopBeginning)
					v.push_back(t);
					//else
					//	v.push_back(t - firstTickTime);
					
					v.push_back(j->getPitch());
					v.push_back(j->getVelocity());
					v.push_back(j->getDuration());
				 */
					/*
					myMidiEvents.recordedNoteOnMatrix.push_back(v);
					myMidiEvents.noteOnMatches.push_back(false);
					myMidiEvents.beatPositions.push_back(newBeatLocation);
					*/
					
					break;
					
				case MIDI_POLY_AFTERTOUCH:
					if (printMidiInfo)
						std::cout << t << ": Polyphonic aftertouch: channel " << ch
						<< " pitch " << j->getPitch()
						<< " pressure " << j->getData2() << std::endl;
					break;
					
				case MIDI_CTRL_CHANGE:
				{
					int controller = j->getData1();
					std::string name;
					switch (controller) {
						case MIDI_CONTROLLER_BANK_MSB: name = "Bank select MSB"; break;
						case MIDI_CONTROLLER_VOLUME: name = "Volume"; break;
						case MIDI_CONTROLLER_BANK_LSB: name = "Bank select LSB"; break;
						case MIDI_CONTROLLER_MODULATION: name = "Modulation wheel"; break;
						case MIDI_CONTROLLER_PAN: name = "Pan"; break;
						case MIDI_CONTROLLER_SUSTAIN: name = "Sustain"; break;
						case MIDI_CONTROLLER_RESONANCE: name = "Resonance"; break;
						case MIDI_CONTROLLER_RELEASE: name = "Release"; break;
						case MIDI_CONTROLLER_ATTACK: name = "Attack"; break;
						case MIDI_CONTROLLER_FILTER: name = "Filter"; break;
						case MIDI_CONTROLLER_REVERB: name = "Reverb"; break;
						case MIDI_CONTROLLER_CHORUS: name = "Chorus"; break;
						case MIDI_CONTROLLER_NRPN_1: name = "NRPN 1"; break;
						case MIDI_CONTROLLER_NRPN_2: name = "NRPN 2"; break;
						case MIDI_CONTROLLER_RPN_1: name = "RPN 1"; break;
						case MIDI_CONTROLLER_RPN_2: name = "RPN 2"; break;
						case MIDI_CONTROLLER_SOUNDS_OFF: name = "All sounds off"; break;
						case MIDI_CONTROLLER_RESET: name = "Reset"; break;
						case MIDI_CONTROLLER_LOCAL: name = "Local"; break;
						case MIDI_CONTROLLER_ALL_NOTES_OFF: name = "All notes off"; break;
					}
					if (printMidiInfo)
						std::cout << t << ": Controller change: channel " << ch
						<< " controller " << j->getData1();
					if (name != "") std::cout << " (" << name << ")";
					std::cout << " value " << j->getData2() << std::endl;
              //      lastMillis = 0;
              //      lastTick = 0;
				}
					break;
					
				case MIDI_PROG_CHANGE:
					if (printMidiInfo)
                    	std::cout << t << ": Program change: channel " << ch
						<< " program " << j->getData1() << std::endl;
                    //Singleton<GameManager>::GetInst()->gameTotalTime[ch] = 0;
                    //lastTick = 0;
                    break;
					
				case MIDI_CHNL_AFTERTOUCH:
					if (printMidiInfo)
						std::cout << t << ": Channel aftertouch: channel " << ch
						<< " pressure " << j->getData1() << std::endl;
					break;
					
				case MIDI_PITCH_BEND:
					if (printMidiInfo)
						std::cout << t << ": Pitch bend: channel " << ch
						<< " value " << (int)j->getData2() * 128 + (int)j->getData1() << std::endl;
					break;
					
				case MIDI_SYSTEM_EXCLUSIVE:
					if (printMidiInfo)
						std::cout << t << ": System exclusive: code "
						<< (int)j->getMessageType() << " message length " <<
						j->getMetaMessage().length() << std::endl;
					break;
					
					
			}
        }
        
        //std::vector<noteData> copymidiEvents;
        //copymidiEvents.resize(midiEvents.size());
        //copy(midiEvents.begin(), midiEvents.end(), copymidiEvents.begin());
        CCLog("i->first : %d",i->first);
       // if(i->first > 0)
       // {
            if(midiEvents.size() > 0)
            {
                Singleton<GameManager>::GetInst()->midiChannel.push_back(midiEvents);
                Singleton<GameManager>::GetInst()->channelState = false;
                
                 
                Singleton<GameManager>::GetInst()->saveTime.push_back(0);//출력되기전 시간
                Singleton<GameManager>::GetInst()->firstTimeDelay.push_back(0);
                Singleton<GameManager>::GetInst()->nodePrintCount_Channel.push_back(0);
                Singleton<GameManager>::GetInst()->removeNodeCount.push_back(0);
                Singleton<GameManager>::GetInst()->deleteGuideCount.push_back(0);
                Singleton<GameManager>::GetInst()->guidePrintCount.push_back(0);
                Singleton<GameManager>::GetInst()->eraseCount.push_back(0);
                Singleton<GameManager>::GetInst()->guideCount.push_back(0);
                
                CCArray *guide = CCArray::create();
                guide->retain();
                Singleton<GameManager>::GetInst()->guide_Total_Array_channel.push_back(guide);
                
                CCArray *guide_copy = CCArray::create();
                guide_copy->retain();
                Singleton<GameManager>::GetInst()->guide_Total_Array_channel_copy.push_back(guide_copy);
                
                
                if(Singleton<GameManager>::GetInst()->gameMode == SINGE_GAME)
                {
                    if(Singleton<GameManager>::GetInst()->_collision_boxes.size() > 0)
                    {
                        Singleton<GameManager>::GetInst()->_collision_boxes_Channel.push_back(Singleton<GameManager>::GetInst()->_collision_boxes);
                    }
                    
                }
                else if(Singleton<GameManager>::GetInst()->gameMode == ANG_GAME)
                {
                    if(Singleton<GameManager>::GetInst()->_collision_boxes.size() > 0)
                    {
                 
                        Singleton<GameManager>::GetInst()->_collision_boxes_Channel.push_back(Singleton<GameManager>::GetInst()->_collision_boxes);
                        Singleton<GameManager>::GetInst()->_collision_boxes_Channel_copy.push_back(Singleton<GameManager>::GetInst()->_collision_boxes_copy);
                 
                    }
                }
                
                //Singleton<GameManager>::GetInst()->makeCollisinoBoxes_update(NULL,Singleton<GameManager>::GetInst()->midiChannel.size()-1);
                
                std::vector<noteData> vClear;
                midiEvents.swap(vClear);
                midiEvents.clear();
                
            }
        //}
 
	}
    
  
    return 1;
}//end midi main reading


double MIDIFileLoader::updateElapsedTime(int ticksNow){
    //CCLOG("ticksNow : %d   %d",ticksNow,lastTick);
	double millisNow = ((beatPeriod * (ticksNow - lastTick)) / (double) pulsesPerQuarternote);//update time elapsed since we last updated
	//printf("ticks elapsed %i, last millis %f elapsed millis %f\n", (ticksNow - lastTick), lastMillis, millisNow);
	
	millisNow += lastMillis;
	
	lastTick = ticksNow;
	lastMillis = millisNow;
	
	return millisNow;
}

double MIDIFileLoader::ticksToMillis(int ticks){
	return (beatPeriod * ticks / (double) pulsesPerQuarternote);
}

