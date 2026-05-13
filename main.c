#include "plugin.h"

#define PLUGIN_NAME L"TestPlugin"

PPH_PLUGIN PluginInstance;
HINSTANCE PluginInstanceHandle;

PH_CALLBACK_REGISTRATION MainMenuInitializingCallbackRegistration;
PH_CALLBACK_REGISTRATION MenuItemCallbackRegistration;

INT_PTR CALLBACK MainDialogProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    )
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        {
            PhCenterWindow(hwndDlg, GetParent(hwndDlg));
        }
        break;
    case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
            case IDOK:
            case IDCANCEL:
                EndDialog(hwndDlg, IDOK);
                break;
            }
        }
        break;
    }

    return FALSE;
}

_Function_class_(PH_PLUGIN_CALLBACK_FUNCTION)
VOID NTAPI MenuItemCallback(
    _In_opt_ PVOID Parameter,
    _In_opt_ PVOID Context
    )
{
    PPH_PLUGIN_MENU_ITEM menuItem = (PPH_PLUGIN_MENU_ITEM)Parameter;

    if (menuItem && menuItem->Id == ID_TEST_MENU_ITEM)
    {
        PhDialogBox(
            PluginInstanceHandle,
            MAKEINTRESOURCE(IDD_MAIN_DIALOG),
            (HWND)menuItem->Context,
            MainDialogProc,
            NULL
        );
    }
}

_Function_class_(PH_CALLBACK_FUNCTION)
VOID NTAPI MainMenuInitializingCallback(
    _In_opt_ PVOID Parameter,
    _In_opt_ PVOID Context
    )
{
    PPH_PLUGIN_MENU_INFORMATION menuInfo = (PPH_PLUGIN_MENU_INFORMATION)Parameter;
    PPH_EMENU_ITEM menuItem;

    if (!menuInfo || menuInfo->u.MainMenu.SubMenuIndex != PH_MENU_ITEM_LOCATION_TOOLS)
        return;

    menuItem = PhPluginCreateEMenuItem(PluginInstance, 0, ID_TEST_MENU_ITEM, L"Test Plugin", (PVOID)menuInfo->OwnerWindow);
    PhInsertEMenuItem(menuInfo->Menu, menuItem, ULONG_MAX);
}

LOGICAL DllMain(
    _In_ HINSTANCE Instance,
    _In_ ULONG Reason,
    _Reserved_ PVOID Reserved
    )
{
    if (Reason == DLL_PROCESS_ATTACH)
    {
        PPH_PLUGIN_INFORMATION info;
        PluginInstanceHandle = Instance;
        PluginInstance = PhRegisterPlugin(PLUGIN_NAME, Instance, &info);

        if (!PluginInstance)
            return FALSE;

        info->DisplayName = L"Test Plugin";
        info->Description = L"A template plugin for testing purposes.";

        PhRegisterCallback(PhGetGeneralCallback(GeneralCallbackMainMenuInitializing), MainMenuInitializingCallback, NULL, &MainMenuInitializingCallbackRegistration);
        PhRegisterCallback(PhGetPluginCallback(PluginInstance, PluginCallbackMenuItem), MenuItemCallback, NULL, &MenuItemCallbackRegistration);
    }

    return TRUE;
}
