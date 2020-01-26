// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlayableDemoCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Global.h"

//////////////////////////////////////////////////////////////////////////
// APlayableDemoCharacter

APlayableDemoCharacter::APlayableDemoCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Global::SetDefaultCamera(FollowCamera);
	Global::SetDefaultCamera(/*dynamic_cast<AActor*>*/(this));
	Global::TimeToActorCam = TimeToSwitchBackToThisActor;

	//Global::SetDefaultPlayerController(this->GetPlay);
	//Global::OurPlayer = this->GetWorld()->GetFirstPlayerController();
//	Global::SetDefaultPlayerController(GetWorld()->GetFirstPlayerController());

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void APlayableDemoCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("LClick", IE_Pressed, this, &APlayableDemoCharacter::LPress);
	PlayerInputComponent->BindAction("RClick", IE_Pressed, this, &APlayableDemoCharacter::RPress);
	PlayerInputComponent->BindAction("LClick", IE_Released, this, &APlayableDemoCharacter::LRelease);
	PlayerInputComponent->BindAction("RClick", IE_Released, this, &APlayableDemoCharacter::RRelease);
	PlayerInputComponent->BindAction("Escape", IE_Released, this, &APlayableDemoCharacter::Escape);
	//nums
	PlayerInputComponent->BindAction("num0", IE_Released, this, &APlayableDemoCharacter::Num0);
	PlayerInputComponent->BindAction("num1", IE_Released, this, &APlayableDemoCharacter::Num1);
	PlayerInputComponent->BindAction("num2", IE_Released, this, &APlayableDemoCharacter::Num2);
	PlayerInputComponent->BindAction("num3", IE_Released, this, &APlayableDemoCharacter::Num3);
	PlayerInputComponent->BindAction("num4", IE_Released, this, &APlayableDemoCharacter::Num4);
	PlayerInputComponent->BindAction("num5", IE_Released, this, &APlayableDemoCharacter::Num5);
	PlayerInputComponent->BindAction("num6", IE_Released, this, &APlayableDemoCharacter::Num6);
	PlayerInputComponent->BindAction("num7", IE_Released, this, &APlayableDemoCharacter::Num7);
	PlayerInputComponent->BindAction("num8", IE_Released, this, &APlayableDemoCharacter::Num8);
	PlayerInputComponent->BindAction("num9", IE_Released, this, &APlayableDemoCharacter::Num9);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayableDemoCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayableDemoCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayableDemoCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayableDemoCharacter::LookUpAtRate);



	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayableDemoCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &APlayableDemoCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &APlayableDemoCharacter::OnResetVR);
}


void APlayableDemoCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void APlayableDemoCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void APlayableDemoCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void APlayableDemoCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayableDemoCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlayableDemoCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayableDemoCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void APlayableDemoCharacter::LPress()  {	Global::HandleInput(Global::LClick_Pressed);	}
void APlayableDemoCharacter::LRelease(){	Global::HandleInput(Global::LClick_Released);	}
void APlayableDemoCharacter::RPress()  {	Global::HandleInput(Global::RClick_Pressed);	}
void APlayableDemoCharacter::RRelease(){	Global::HandleInput(Global::RClick_Released);	}
void APlayableDemoCharacter::Escape(){		Global::HandleInput(Global::Esc);	}
//nums
void APlayableDemoCharacter::Num0(){		Global::HandleInput(Global::N0);	}
void APlayableDemoCharacter::Num1(){		Global::HandleInput(Global::N1);	}
void APlayableDemoCharacter::Num2(){		Global::HandleInput(Global::N2);	}
void APlayableDemoCharacter::Num3(){		Global::HandleInput(Global::N3);	}
void APlayableDemoCharacter::Num4(){		Global::HandleInput(Global::N4);	}
void APlayableDemoCharacter::Num5(){		Global::HandleInput(Global::N5);	}
void APlayableDemoCharacter::Num6(){		Global::HandleInput(Global::N6);	}
void APlayableDemoCharacter::Num7(){		Global::HandleInput(Global::N7);	}
void APlayableDemoCharacter::Num8(){		Global::HandleInput(Global::N8);	}
void APlayableDemoCharacter::Num9(){		Global::HandleInput(Global::N9);	}