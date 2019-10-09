// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"

#include "ColorChanger.generated.h"

/**
 * 
 */

class AAnimationController;

UCLASS()
class PLAYABLEDEMO_API UColorChanger : public USpotLightComponent
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, Category = "Custom Setup")
	AAnimationController* ControllerToSendAndRecieve = nullptr;

	UPROPERTY(EditAnywhere, Category = "Custom Setup")


	AActor* owner = nullptr;

	UColorChanger();
	~UColorChanger();
};
