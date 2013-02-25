// --------------------------------
// Condition menu
// --------------------------------

#ifdef CONDITION_MENU

	//ITEM(0, "Evaluated condition")
	//SEPARATOR
	//ITEM(1, "Triggered condition")

	SUB_START("Left side")
		ITEM(0, "Left/Top")
		ITEM(1, "Left/Middle")
		ITEM(2, "Left/Bottom")
	SUB_END
	SUB_START("Middle")
		ITEM(3, "Middle/Top")
		ITEM(4, "Center")
		ITEM(5, "Middle/Bottom")
	SUB_END
	SUB_START("Right side")
		ITEM(6, "Right/Top")
		ITEM(7, "Right/Middle")
		ITEM(8, "Right/Bottom")
	SUB_END

#endif

// --------------------------------
// Action menu
// --------------------------------

#ifdef ACTION_MENU

	// You have access to edPtr and you can throw in normal C++
	// code wherever you want in any of these menus. If you want to
	// show certain conditions based on a property (a la OINC socket)
	// use the property's value stored in edPtr:

	// if(edPtr->ShowAdvancedOptions)
	// {
	//		SUB_START("Bake pie")
	//			ITEM(0, "Apple pie")
	//			ITEM(1, "Mince pie")
	//		SUB_END
	// }
	// else
	// {
	//		ITEM(0, "Bake apple pie")
	// }

	// You could do some pretty cool stuff with this, like loading a
	// menu from an external source (ActiveX object?)

	// for(int i=0;i<edPtr->ActionCount;i++)
	//		ITEM(i,edPtr->Actions[i])

	// This will run every time the menu is opened in MMF2, so don't
	// make it too slow or it could get annoying

	//SUB_START("This is a submenu")
	//	ITEM(0,"Trigger condition")
	//SUB_END
	//SEPARATOR
	//ITEM(1,"Dummy action")

	SUB_START("Box Properties")
		ITEM(0,"Set Tile Width")
		ITEM(1,"Set Tile Height")
		SEPARATOR
		ITEM(2,"Set Box Width")
		ITEM(3,"Set Box Height")
		SEPARATOR
		ITEM(4,"Set Box Start Position")
	SUB_END
	ITEM(5,"Generate Box")

#endif


// --------------------------------
// Expression menu
// --------------------------------

#ifdef EXPRESSION_MENU

	ITEM(0,"Last X")
	//SEPARATOR
	ITEM(1,"Last Y")

#endif