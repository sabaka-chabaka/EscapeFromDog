// copyright 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "Key.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class ESCAPEFROMDOG_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(Blueprintable)
	bool CanEnd() const;
		
protected:
	UPROPERTY(EditAnywhere, Category="Camera")
	class UCameraComponent* Camera;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	void Turn(float Value);
	void LookUp(float Value);
	
	void JumpNoise();
	
	void UnNoise(float DeltaTime);
	
	void Collect();
	
	UPROPERTY()
	TArray<AKey*> Keys;
	
public:
	float Noise;
};
