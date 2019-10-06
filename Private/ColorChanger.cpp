// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorChanger.h"
#include "AnimationController.h"

UColorChanger::UColorChanger() {

	owner = this->GetOwner();

	if (!owner) { return; }

	if (dynamic_cast<ULightComponent*>(owner)) {
		int32 breakasd = 2332;
	}
	int32 asdsa = 11011;

	if (dynamic_cast<USpotLightComponent*>(owner)) {
		int32 breakasd = 2332;
	}
	if (dynamic_cast<USpotLightComponent*>(owner->GetRootComponent())) {
		int32 breakasd = 2332; //WORKS
	}
	if (dynamic_cast<ULightComponent*>(owner->GetRootComponent())) {
		int32 breakasd = 2332; //WORKS
	}
}

UColorChanger::~UColorChanger() {

};