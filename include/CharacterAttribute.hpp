#pragma once

class CharacterAttributes {
public:
	int will = 1; //hp applied levelling up
	int arcane = 1; //damage applied on cast
	int dexterity = 1; //cooldowns applied levelling up
	int luck = 1; //critical hits not applied yet
	int fitess = 1; //speed applied on inherited characters
	int points = 0; //points used to level up
};