#include "AI/ScriptDevAI/ScriptDevAIMgr.h"
#include "AI/ScriptDevAI/ScriptDevMgr.h"
#include "World/World.h"
#include "boost/date_time/gregorian/gregorian.hpp"

class xp_weekend : public PlayerScript
{
public:
    xp_weekend() : PlayerScript("mod_xpweeknd") { }

    bool IsWeekend()
    {
        if (boost::date_time::Friday || boost::date_time::Saturday || boost::date_time::Sunday)
            return true;

        return false;
    }

    void OnLogin(Player* player) override
    {
        ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00DoubleXP Weekend |r");

        if (IsWeekend())
        {
            player->CastSpell(player, 47004, TRIGGERED_OLD_TRIGGERED);
            ChatHandler(player->GetSession()).SendSysMessage("Its the Weekend...Double XP Activated!");
            player->HandleEmote(ANIM_EMOTE_DANCE);
        }
           
    }

    void OnGiveXP(Player* p, uint32& amount, Creature* victim) override
    {
        if (IsWeekend())
            amount *= 2;
        else
            amount == amount;
    }
};

void Addmod_xpweekendScripts()
{
    new xp_weekend();
}