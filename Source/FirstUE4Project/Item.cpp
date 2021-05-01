// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Getters setters
int AItem::getItemID() { return ItemID; }
void AItem::setItemID(int id) { ItemID = id; }
FString AItem::getItemName() { return ItemName; }
void AItem::setItemName(FString name) { ItemName = name; }
float AItem::getSpawnProb() { return spawnProb; }
void AItem::setSpawnProb(float prob) { spawnProb = prob; }
