// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteCam.h"
#include "AnimationController.h"
#include "Global.h"

ANoteCam::ANoteCam() {

};

ANoteCam::~ANoteCam()
{
}

void ANoteCam::BeginPlay()
{
	Super::BeginPlay();
	
	if (DaddyController) {
		DaddyController->RecieveNoteCam(this);
	}
	else {
		//TODO log error, no sugar daddy
	}

}

void ANoteCam::RecieveEvent(FString _event) {

	if (IgnoreAllLocks) {
		ProcessEvent(_event);
		return;
	}

	if (ShouldLock1BeTrue) {
		if (DaddyController->lock1) {
			ProcessEvent(_event);
		}
		else { return; }
	}
	if (ShouldLock2BeTrue) {
		if (DaddyController->lock2) {
			ProcessEvent(_event);
		}
		else { return; }
	}if (ShouldLock3BeTrue) {
		if (DaddyController->lock3) {
			ProcessEvent(_event);
		}
		else { return; }
	}


}

void ANoteCam::ProcessEvent(FString _event)
{
	for (auto& evn : SwitchHereOnEvents) {
		if (evn == _event) {
			if (TestActorOverride) {
				Global::SwitchToCamera(TestActorOverride);
				return;
			}
			Global::SwitchToCamera(this);
			return;
		}
	}



}
