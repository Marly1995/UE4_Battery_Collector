// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"


// set default values
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

	// base power level
	BatteryPower = 150.0f;
}

void ABatteryPickup::WasCollected_Implementation()
{
	// use the base pickup behaviour
	Super::WasCollected_Implementation();
	// destroy the battery
	Destroy();
}

float ABatteryPickup::GetPower()
{
	// returns battery power
	return BatteryPower;
}