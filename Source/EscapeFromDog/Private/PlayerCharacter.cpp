// copyright 2026 sabaka-chabaka

#include "EscapeFromDog/Public/PlayerCharacter.h"
#include "EscapeFromDog/Public/Key.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UnNoise(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::JumpNoise);
	PlayerInputComponent->BindAction("Collect", IE_Pressed, this, &APlayerCharacter::Collect);
	
	PlayerInputComponent->BindAxis("Forward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("Look", this, &APlayerCharacter::LookUp);
}

void APlayerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::JumpNoise()
{
	Jump();
	
	Noise = 100.0f;
}

void APlayerCharacter::UnNoise(float DeltaTime)
{
	if (Noise > 1.0f)
	{
		Noise = FMath::FInterpTo(Noise, 0.0f, DeltaTime, 0.5f);
	}
	else if (Noise <= 1.0f)
	{
		Noise = 0.0f;
	}
}

void APlayerCharacter::Collect()
{
	FHitResult Hit;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Camera->GetComponentLocation(), Camera->GetComponentLocation() + Camera->GetForwardVector() * 1000.0f, ECC_Visibility))
	{
		if (AKey* Key = Cast<AKey>(Hit.GetActor()))
		{
			Key->SetActorHiddenInGame(true);
			Keys.Add(Key);
		}
	}
}