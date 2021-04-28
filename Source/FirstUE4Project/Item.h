// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class FIRSTUE4PROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int getItemID();
	void setItemID(int id);
	FString getItemName();
	void setItemName(FString name);
	float AItem::getSpawnProb();
	void AItem::setSpawnProb(float prob);

private:

	int ItemID = -1;
	FString ItemName = "UNASSIGNED";

	int ItemType = -1;
	float spawnProb = 0.f;
};
