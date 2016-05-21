#include "AnimationTrack.h"

extern "C" {
	void Oni_Animation_Track_update(Oni_Animation_TrackPtr obj, double dt){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->update(dt);
	}
		
	// Accessors and Mutators
	void Oni_Animation_Track_setPlaybackRate(Oni_Animation_TrackPtr obj, double rate){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->setPlaybackRate(rate);
	}
	
	double Oni_Animation_Track_getPlaybackRate(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		return track->getPlaybackRate();
	}
	
	const char* Oni_Animation_Track_getAnimationName(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		return track->getAnimationName().c_str();
	}
	
	double Oni_Animation_Track_getTimePosition(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		return track->getTimePosition();
	}
	
	void Oni_Animation_Track_setTimePosition(Oni_Animation_TrackPtr obj, double timePos){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->setTimePosition(timePos);
	}
	
	double Oni_Animation_Track_getLength(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		return (double)(track->getLength());
	}
	
	void Oni_Animation_Track_setLength(Oni_Animation_TrackPtr obj, double len){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->setLength(len);
	}
	
	double Oni_Animation_Track_getWeight(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		return (double)(track->getWeight());
	}
	
	void Oni_Animation_Track_setWeight(Oni_Animation_TrackPtr obj, double weight){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->setWeight(weight);
	}
	
	void Oni_Animation_Track_addTime(Oni_Animation_TrackPtr obj, double offset){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->addTime(offset);
	}
	
	int Oni_Animation_Track_hasEnded(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		if(track->hasEnded())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	int Oni_Animation_Track_getEnabled(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		if(track->getEnabled())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	void Oni_Animation_Track_setEnabled(Oni_Animation_TrackPtr obj, int enabled){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->setEnabled(enabled);
	}
	
	void Oni_Animation_Track_setLoop(Oni_Animation_TrackPtr obj, int loop){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->setLoop(loop);
	}
	
	int Oni_Animation_Track_getLoop(Oni_Animation_TrackPtr obj){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		if(track->getLoop())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}