#include "AI/ScriptDevAI/ScriptDevAIMgr.h"
#include "AI/ScriptDevAI/ScriptDevMgr.h"
#include "World/World.h"

class modsample : public PlayerScript
{
public:
    modsample() : PlayerScript("modsample") { }

    void OnLogin(Player* player) override
    {
        ChatHandler(player->GetSession()).SendSysMessage("Dynamic Module Is working!!");
        std::string mod = sWorld.GetModuleStringConfig("modsample.stringtest", "The is the Sameple Module");
        uint32 number = sWorld.GetModuleIntConfig("modsample.intTest", 10032);

        if (sWorld.GetModuleBoolConfig("modsample.enableHelloWorld", "1"))
        {
            ChatHandler(player->GetSession()).SendSysMessage("GetModuleBoolConfig get true");
            ChatHandler(player->GetSession()).SendSysMessage(mod.c_str());
            player->CastSpell(player, number, TRIGGERED_OLD_TRIGGERED);
        }
        else
            ChatHandler(player->GetSession()).SendSysMessage("GetModuleBoolConfig get false");
    }
};

void Addmod_sampleScripts()
{
    new modsample();
}