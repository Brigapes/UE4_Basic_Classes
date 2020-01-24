// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Engine/TriggerBox.h"

//#include "AnimationActor.h"
#include "AnimationController.h"

#include "ActionOnTrigger.generated.h"
/**
 * 
 */
UCLASS()
class PLAYABLEDEMO_API AActionOnTrigger : public ATriggerBox
{
	GENERATED_BODY()


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AActionOnTrigger();


	UPROPERTY(EditAnywhere, Category = "Custom setup")
		AActor* ActorToTriggerOn = nullptr;
	UPROPERTY(EditAnywhere, Category = "Custom setup")
		AActor* ActorToChange = nullptr;
	UPROPERTY(EditAnywhere, Category = "Custom setup")
		AAnimationController* AnimationControllerToSendEvents = nullptr;
	UPROPERTY(EditAnywhere, Category = "Custom setup")
		FString EventNameForTrigger = "";
	UPROPERTY(EditAnywhere, Category = "Custom setup")
		FString EventNameForLeave = "";
	UPROPERTY(EditAnywhere, Category = "Custom setup")
		bool ForceDefaultCameraOnLeave = false;

///	UPROPERTY(EditAnywhere, Category = "Custom setup")
///		TArray<AActor*> AnimationActors = {};
	///UPROPERTY(EditAnywhere)
	///	ACharacter* CharacterToTransform = nullptr;

	UPROPERTY(EditAnywhere)
		bool ignoreFirstTime = false;
//	UPROPERTY(EditAnywhere)
//		bool ExitOnTrigger = false;

	UPROPERTY(EditAnywhere)
		bool SeeBoundBox = false;



//	UPROPERTY(EditAnywhere)
//		FVector LocationToTeleportCurrentOffset = FVector(0, 0, 0);

	// create trigger capsule
//	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
//		class UCapsuleComponent* TriggerCapsule;
	
	//SEND EVENT IN GENERAL
	UPROPERTY(EditAnywhere, Category = "Animation")
		bool AnimateActors = true; //special case
	UPROPERTY(EditAnywhere, Category = "Animation")
		bool SendEventOnTrigger = false; //special case
	UPROPERTY(EditAnywhere, Category = "Animation")
		bool SendEventOnLeave = false; //special case



	UPROPERTY(EditAnywhere, Category = "Do What Action On Trigger?")
		bool HideOnTrigger = false;
	UPROPERTY(EditAnywhere, Category = "Do What Action On Trigger?")
		bool ShowOnTrigger = false;
	UPROPERTY(EditAnywhere, Category = "Do What Action On Trigger?")
		bool TransformOnTrigger = false;
	UPROPERTY(EditAnywhere, Category = "Do What Action On Trigger?")
		bool TeleportOnTrigger = false;

	UPROPERTY(EditAnywhere, Category = "Do What Action On Leave?")
		bool HideOnLeave = false;
	UPROPERTY(EditAnywhere, Category = "Do What Action On Leave?")
		bool ShowOnLeave = false;
	UPROPERTY(EditAnywhere, Category = "Do What Action On Leave?")
		bool TransformOnLeave = false;
	UPROPERTY(EditAnywhere, Category = "Do What Action On Leave?")
		bool TeleportOnLeave = false;

	UPROPERTY(EditAnywhere, Category = "Action parameters")
		FVector TeleportTo;
	UPROPERTY(EditAnywhere, Category = "Action parameters")
		FRotator RotateTo;





	//UPROPERTY(VisibleAnywhere, Category = "Action parameters")
	//	FRotator RotateTo;




	// declare overlap end function
	///UFUNCTION()
		///void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
///	UPROPERTY(EditAnywhere)
///		class AActor* SpecificActor;

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};
