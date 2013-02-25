// ============================================================================
//
// This file contains the actions, conditions and expressions your object uses
// 
// ============================================================================

#include "common.h"

// ============================================================================
//
// CONDITIONS
// 
// ============================================================================

CONDITION(
	/* ID */			0,
	/* Name */			"%o: On type %0 top left",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentX[type] == 0 && rdPtr->currentY[type] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CONDITION(
	/* ID */			1,
	/* Name */			"%o: On type %0 middle left",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentX[type] == 0 && rdPtr->currentY[type] > 0 && rdPtr->currentY[type] < rdPtr->boxHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CONDITION(
	/* ID */			2,
	/* Name */			"%o: On type %0 bottom left",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentX[type] == 0 && rdPtr->currentY[type] == rdPtr->boxHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}


CONDITION(
	/* ID */			3,
	/* Name */			"%o: On type %0 top middle",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentX[type] > 0 && rdPtr->currentY[type] == 0 && rdPtr->currentX[type] < rdPtr->boxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CONDITION(
	/* ID */			4,
	/* Name */			"%o: On type %0 center",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentX[type] > 0 && rdPtr->currentY[type] > 0 && rdPtr->currentY[type] < rdPtr->boxHeight && rdPtr->currentX[type] < rdPtr->boxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}
CONDITION(
	/* ID */			5,
	/* Name */			"%o: On type %0 middle bottom",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentX[type] > 0 && rdPtr->currentY[type] == rdPtr->boxHeight && rdPtr->currentX[type] < rdPtr->boxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}
CONDITION(
	/* ID */			6,
	/* Name */			"%o: On type %0 right top",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentY[type] == 0 && rdPtr->currentX[type] == rdPtr->boxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}
CONDITION(
	/* ID */			7,
	/* Name */			"%o: On type %0 right middle",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentY[type] > 0 && rdPtr->currentY[type] < rdPtr->boxHeight && rdPtr->currentX[type] == rdPtr->boxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}
CONDITION(
	/* ID */			8,
	/* Name */			"%o: On type %0 right bottom",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"Type")
) {
	int type=Param(TYPE_INT);
	if(rdPtr->currentY[type] == rdPtr->boxHeight && rdPtr->currentX[type] == rdPtr->boxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// ============================================================================
//
// ACTIONS
// 
// ============================================================================
ACTION(
	/* ID */			0,
	/* Name */			"Set Tile Width to %0",
	/* Flags */			0,
	/* Params */		(1, PARAM_NUMBER, "Width (in pixels)")
) {
	rdPtr->tileWidth = Param(TYPE_INT);
}
ACTION(
	/* ID */			1,
	/* Name */			"Set Tile Height to %0",
	/* Flags */			0,
	/* Params */		(1, PARAM_NUMBER, "Height (in pixels)")
) {
	rdPtr->tileHeight = Param(TYPE_INT);
}
ACTION(
	/* ID */			2,
	/* Name */			"Set Box Width to %0",
	/* Flags */			0,
	/* Params */		(1, PARAM_NUMBER, "Width (in tiles)")
) {
	rdPtr->boxWidth = Param(TYPE_INT)-1;
}
ACTION(
	/* ID */			3,
	/* Name */			"Set Box Height to %0",
	/* Flags */			0,
	/* Params */		(1, PARAM_NUMBER, "Height (in tiles)")
) {
	rdPtr->boxHeight = Param(TYPE_INT)-1;
}
ACTION(
	/* ID */			4,
	/* Name */			"Set Box Start Position (%0, %1)",
	/* Flags */			0,
	/* Params */		(2, PARAM_NUMBER, "X Position of top left", PARAM_NUMBER, "Y Position of top left")
) {
	rdPtr->startX = Param(TYPE_INT);
	rdPtr->startY = Param(TYPE_INT);
}

ACTION(
	/* ID */			5,
	/* Name */			"Generate Box type %0",
	/* Flags */			0,
	/* Params */		(1, PARAM_NUMBER, "Type")
) {
	int curType = Param(TYPE_INT);

	for(int x = 0; x <= rdPtr->boxWidth; x++)
	{
		for(int y=0; y <= rdPtr->boxHeight; y++)
		{
			rdPtr->currentY[curType] = y;
			rdPtr->currentX[curType] = x;
			if(y == 0 && x == 0)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(0);
			}
			if(x == 0 && y > 0 && y < rdPtr->boxHeight)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(1);
			}
			if(x==0 && y == rdPtr->boxHeight)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(2);
			}
			if(x > 0 && x < rdPtr->boxWidth && y == 0)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(3);
			}
			if(x > 0 && x < rdPtr->boxWidth && y > 0 && y < rdPtr->boxHeight)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(4);
			}
			if(x > 0 && x < rdPtr->boxWidth && y == rdPtr->boxHeight)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(5);
			}
			if(x == rdPtr->boxWidth && y == 0)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(6);
			}
			if(x == rdPtr->boxWidth && y > 0 && y < rdPtr->boxHeight)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(7);
			}
			if(x == rdPtr->boxWidth && y == rdPtr->boxHeight)
			{
				rdPtr->lastX = rdPtr->startX + rdPtr->tileWidth * x;
				rdPtr->lastY = rdPtr->startY + rdPtr->tileHeight * y;
				rdPtr->rRd->GenerateEvent(8);
			}
		}
	}

	rdPtr->currentX[curType] = -1;
	rdPtr->currentY[curType] = -1;
}

// ============================================================================
//
// EXPRESSIONS
// 
// ============================================================================

EXPRESSION(
	/* ID */			0,
	/* Name */			"LastX(",
	/* Flags */			0,
	/* Params */		(0)
) {	
	return rdPtr->lastX;
}

EXPRESSION(
	/* ID */			1,
	/* Name */			"LastY(",
	/* Flags */			0,
	/* Params */		(0)
) {
	return rdPtr->lastY;
}