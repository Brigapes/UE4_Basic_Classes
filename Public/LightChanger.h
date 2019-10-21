// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SpotLightComponent.h"
#include "AnimationController.h"
#include "LightChanger.generated.h"

/*USTRUCT()
	struct FSingleColorData
{
	GENERATED_BODY()

		//Always make USTRUCT variables into UPROPERTY()
		//    any non-UPROPERTY() struct vars are not replicated

		// So to simplify your life for later debugging, always use UPROPERTY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Events And Lights")
		int32 SampleInt32;

};*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLAYABLEDEMO_API ULightChanger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULightChanger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



//	UPROPERTY(EditAnywhere, Category = "Events And Lights")
//		TArray<FSingleColorData> AllEvents = {};
	UPROPERTY(EditAnywhere, Category = "Events And Lights")
		AAnimationController* AnimationController;

	UPROPERTY(EditAnywhere, Category = "Event 1")
		FString OnEvent1 = "";
	UPROPERTY(EditAnywhere, Category = "Event 1")
		FColor ToColor1;// = FColor(255, 255, 255, 255);

	UPROPERTY(EditAnywhere, Category = "Event 2")
		FString OnEvent2 = "";
	UPROPERTY(EditAnywhere, Category = "Event 2")
		FColor ToColor2 = FColor(255, 255, 255, 255);

	UPROPERTY(EditAnywhere, Category = "Event 3")
		FString OnEvent3 = "";
	UPROPERTY(EditAnywhere, Category = "Event 3")
		FColor ToColor3 = FColor(255, 255, 255, 255);


	UPROPERTY(EditAnywhere, Category = "Locks")
		bool IgnoreAllLocks = true;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool IgnoreLocksForLoad = true;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool ShouldLock1BeTrue = false;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool ShouldLock2BeTrue = false;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool ShouldLock3BeTrue = false;

	void ProcessEvent(FString);
	void setColor(FColor);
};
