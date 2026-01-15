/*

Sound Menu
1. Soundlist
2. Sounds: ON/OFF

Saysounds
1. Announcer
2. Scout
3. Pyro
4. Demoman
5. Heavy
6. Engineer
7. Medic
8. Sniper
9. Spy
10. Wheatley
11. Meramus
12. Misc
13. Soldier


Announcer sounds
Friendship will be eliminated
...

*/

#define ALERT     "#announcer_alert"
#define HEAD      "#sword_hit01"
#define CHOICE3   "#choice3"

public Action Menu_Sounds(int client, int args)
{
    if ( client == 0 )
    {
        Snowy_ReplyToCommand(client, "This command is only usable in game.")
        return Plugin_Handled;
    }

    Menu menu = new Menu(MenuHandler1, MENU_ACTIONS_ALL);
    menu.SetTitle("%T", "Menu Title", LANG_SERVER);
    menu.AddItem(ALERT, "Alert!");
    menu.AddItem(HEAD, "Head");
    menu.AddItem(CHOICE3, "Choice 3");
    menu.ExitButton = false;
    menu.Display(client, 20);
    
    return Plugin_Handled;
}

public int MenuHandler1(Menu menu, MenuAction action, int param1, int param2)
{
  switch(action)
  {
    case MenuAction_Start:
    {
      PrintToServer("Displaying menu");
    }
 
    case MenuAction_Display:
    {
      char buffer[255];
      Format(buffer, sizeof(buffer), "%T", "Vote Nextmap", param1);
 
      Panel panel = view_as<Panel>(param2);
      panel.SetTitle(buffer);
      PrintToServer("Client %d was sent menu with panel %x", param1, param2);
    }
 
    case MenuAction_Select:
    {
      char info[32];
      menu.GetItem(param2, info, sizeof(info));
      if (StrEqual(info, CHOICE3))
      {
        PrintToServer("Client %d somehow selected %s despite it being disabled", param1, info);
      }
      else
      {
        PrintToServer("Client %d selected %s", param1, info);
      }
    }
 
    case MenuAction_Cancel:
    {
      PrintToServer("Client %d's menu was cancelled for reason %d", param1, param2);
    }
 
    case MenuAction_End:
    {
      delete menu;
    }
 
    case MenuAction_DrawItem:
    {
      int style;
      char info[32];
      menu.GetItem(param2, info, sizeof(info), style);
 
      if (StrEqual(info, CHOICE3))
      {
        return ITEMDRAW_DISABLED;
      }
      else
      {
        return style;
      }
    }
 
    case MenuAction_DisplayItem:
    {
      char info[32];
      menu.GetItem(param2, info, sizeof(info));
 
      char display[64];
 
      if (StrEqual(info, CHOICE3))
      {
        Format(display, sizeof(display), "%T", "Choice 3", param1);
        return RedrawMenuItem(display);
      }
    }
  }
 
  return 0;
}
 