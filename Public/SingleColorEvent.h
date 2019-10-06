// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SingleColorEvent.generated.h"

/**
 * 
 */
UCLASS()
class PLAYABLEDEMO_API USingleColorEvent : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Events And Lights")
	FColor ToColor = FColor(255, 255, 255, 255);
	UPROPERTY(EditAnywhere, Category = "Events And Lights")
	FString OnEvent = "";
	
};
