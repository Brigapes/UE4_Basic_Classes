// Fill out your copyright notice in the Description page of Project Settings.


#include "LightChanger.h"

// Sets default values for this component's properties
ULightChanger::ULightChanger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void ULightChanger::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//PassAnimToActor = this->GetOwner();
	RegisterComponent();
	if (AnimationController) {
		AnimationController->RecieveLightChangeComponent(this->GetOwner());
	}
	else {
		//TODO log error
		UE_LOG(LogTemp, Error, TEXT("NO ANIMATION CONTROLLER TO RECIEVE EVENTS FROM"));
	}

	setColor(ToColor1);

}


// Called every frame
void ULightChanger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULightChanger::ProcessEvent(FString event) {

	if (AnimationController == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("NO ANIMATION CONTROLLER TO RECIEVE EVENTS FROM"));
		return;
	}

	if (ShouldLock1BeTrue) {
		if (!AnimationController->lock1) {
			return;
		}
	}
	if (ShouldLock2BeTrue) {
		if (!AnimationController->lock2) {
			return;
		}
	}
	if (ShouldLock3BeTrue) {
		if (!AnimationController->lock3) {
			return;
		}
	}

	if (event == OnEvent1) {
		setColor(ToColor1);
	}
	if (event == OnEvent2) {
		setColor(ToColor2);
	}
	if (event == OnEvent3) {
		setColor(ToColor3);
	}

}

void ULightChanger::setColor(FColor color) {

	auto light = dynamic_cast<ULightComponent*>(this->GetOwner()->GetRootComponent());
	if (!light) { UE_LOG(LogTemp, Error, TEXT("NO SPOTLIGHT COMPONENT!!")); return; }

	else {

		//light->get
		//light->SetLightColor(color);
	//	light->SetBloomTint(color);
		//light->SetBloomThreshold
	//	light->SetIntensity(0);
		light->SetLightColor(color);
	}

}