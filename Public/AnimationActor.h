// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AnimationActor.generated.h"


/*DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestDelegate, PARAMTYPE, PARAMNAME);

Example:

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestDelegate, float, Damage);*/


//forward declaration
class AAnimationController;



///DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParam


UCLASS()
class PLAYABLEDEMO_API AAnimationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimationActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	///Stop all animation on this event
	UPROPERTY(EditAnywhere, Category = "Animation General")
		TArray<FString> StopAllAnimationOnEvents = {};
	UPROPERTY(EditAnywhere, Category = "Animation General")
		bool StopRunningAnimsOnNewStart = false;
	UPROPERTY(EditAnywhere, Category = "Animation General")
		AAnimationController* AnimationController;
	UPROPERTY(EditAnywhere, Category = "Animation General")
		bool ForceFinishPosition = false;

	UPROPERTY(EditAnywhere, Category = "Animation 1")
		TArray<FString> AnimateOnEvent1 = {};
	///animation time in frames
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		int32 AnimationTime1 = 0;
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		bool MoveLocation1 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		bool Rotate1 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		bool Scale1 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		FTransform ToTransform1;
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		bool repeatUntilEvent1 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		FString StopEvent1 = "";
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		FString EventToTriggerOnStop1 = "";
	UPROPERTY(EditAnywhere, Category = "Animation 1")
		FString EventToTriggerOnFinish1 = "";


	UPROPERTY(EditAnywhere, Category = "Animation 2")
		TArray<FString> AnimateOnEvent2 = {};
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		int32 AnimationTime2 = 0;
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		bool MoveLocation2 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		bool Rotate2 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		bool Scale2 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		FTransform ToTransform2;
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		bool repeatUntilEvent2 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		FString StopEvent2 = "";
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		FString EventToTriggerOnStop2 = "";
	UPROPERTY(EditAnywhere, Category = "Animation 2")
		FString EventToTriggerOnFinish2 = "";

	UPROPERTY(EditAnywhere, Category = "Animation 3")
		TArray<FString> AnimateOnEvent3 = {};
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		int32 AnimationTime3 = 0;
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		bool MoveLocation3 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		bool Rotate3 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		bool Scale3 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		FTransform ToTransform3;
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		bool repeatUntilEvent3 = false;
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		FString StopEvent3 = "";
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		FString EventToTriggerOnStop3 = "";
	UPROPERTY(EditAnywhere, Category = "Animation 3")
		FString EventToTriggerOnFinish3 = "";



	//main flags for running anim
	bool pl_1 = false;
	bool pl_2 = false;
	bool pl_3 = false;

	void processEvent(FString);
	void StopAllAnims();
	void SendEventToController(FString);

	void StartAnim1();
	void StartAnim2();
	void StartAnim3();

	void StopAnim1();
	void StopAnim2();
	void StopAnim3();

	void ProcessAnims();

	FVector MovePerStep1;
	FVector MovePerStep2;
	FVector MovePerStep3;

	FRotator RotatePerStep1;
	FRotator RotatePerStep2;
	FRotator RotatePerStep3;

	FVector ScalePerStep1;
	FVector ScalePerStep2;
	FVector ScalePerStep3;

	int32 totalSteps1 = -1;
	int32 totalSteps2 = -1;
	int32 totalSteps3 = -1;

};
