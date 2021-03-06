// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h" 
#include "AstroPlanet.h"
#include "AstroCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharacterHatCategory : uint8 {
	Head = 0,
	Mask = 1
};

UCLASS()
class ASTRO_API AAstroCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAstroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
		APlayController* GetPlayController();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		AAstroPlanet* GetLocalPlanet();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		AAstroPlanet* GetLocalSolarBody();

	UFUNCTION(BlueprintCallable)
		void AuthoritySetLocalSolarBody(ASolarBody* solarBody);
	
	UFUNCTION(BlueprintCallable)
		void DetachFromSeat(bool bImmediate, bool bForce);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		UAstroCharacterHat* GetCharacterHat(ECharacterHatCategory category);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		UAstroCharacterPalette* GetCharacterPalette();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		UAstroCharacterSuit* GetCharacterSuit();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		UAstroVisorMaterial* GetCharacterVisorMaterial();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetOnlinePlayerName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* AttachOwner;
};
