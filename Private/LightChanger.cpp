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
	}

}


// Called every frame
void ULightChanger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULightChanger::ProcessEvent(FString) {


}

