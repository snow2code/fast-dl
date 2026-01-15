#if defined _snowy_whitelist_included // _snowy_whitelist_included
  #endinput
#endif
#define _snowy_whitelist_included

#include "whitelist_messages.inc"

#define MAX_WHITELIST       5 // 5

char g_whitelist[MAX_WHITELIST][64] = {
    "STEAM_0:0:874297028",          // Blayze
    "STEAM_0:0:743788633",          // Snowy
    "STEAM_0:0:953546101",          // Snowy's Alt
    "STEAM_0:1:161855942",          // That Guy + Fish
    "STEAM_0:0:67816193"            // Fox
};

void GetJoinMessage(int client, char[] message, int maxlen)
{
    char auth[64];
    char name[64];
    GetClientAuthId(client, AuthId_Steam2, auth, sizeof(auth));
    GetClientName(client, name, sizeof(name));

    if ( StrEqual(auth, "STEAM_0:0:874297028") ) // Blayze
    {
        Format(message, maxlen, "%N joined. Remind me to make join messages -Snowy", client);
    } else if ( StrEqual(auth, "STEAM_0:0:743788633") ) { // Snowy
        // Format(message, maxlen, "%N joined. Remind me to make join messages -Snowy", client);
        PickRandomMessage(g_joinMessage_Snowy, sizeof(g_joinMessage_Snowy), message, maxlen, name);
    } else if ( StrEqual(auth, "STEAM_0:0:953546101") ) { // Alt
        // Fish testing
        if ( StrEqual(name, "Fish") )
        {
            Format(message, maxlen, "Testy test. Fish joined");
        } else {
            Format(message, maxlen, "Testy test. No Fish joined.");
        }
    } else if ( StrEqual(auth, "STEAM_0:1:161855942") ) { // Fish
    } else {
        Format(message, maxlen, "Welcome, %N", client);
    }
}

void PickRandomMessage(const char[][] messages, int messageCount, char[] output, int maxlen, const char[] name)
{
    int index = GetRandomInt(0, messageCount - 1);
    Format(output, maxlen, messages[index], name);
}

bool IsClientWhitelisted(int client)
{
    char auth[64];
    char auth_steamid64[64];
    GetClientAuthId(client, AuthId_Steam2, auth, sizeof(auth));
    GetClientAuthId(client, AuthId_SteamID64, auth_steamid64, sizeof(auth_steamid64));

    // PrintToServer("Checking if %N (%s, %s) is whitelisted.", client, auth, auth_steamid64)
    
    for (int i = 0; i < MAX_WHITELIST; i++)
    {
        if (StrEqual(g_whitelist[i], "null")) continue;

        if (StrEqual(g_whitelist[i], auth))
        {
            // PrintToServer("%N (%s, %s) is whitelisted.", client, auth, auth_steamid64)
            return true;
        }
    }

    return false;
}

// void SGetClientName(int client, char[] output, int outputLen)
// {
//     if (client == 0)
//     {
//         Format(output, outputLen, "Server");
//     } else {
//         char player[64];
//         GetClientName(client, output, outputLen);

//         Format(output, outputLen, "Server");
//     }
// }