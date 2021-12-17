#include <iostream>

#include "Event/include/EventHandler.h"
#include "StateMachine/include/StateManager.h"

int main()
{
    StateManager *state_manager = new StateManager();
    state_manager->Initialize();

    for (;;)
    {
        EventData *data = EventHandler::GetInstance()->Dequeue();

        EventType type = data->GetEventType();
        if (type == EventType::Empty)
        {
            // do nothing if event queue is empty
            delete data;
            continue;
        }
        else if (type == EventType::FinalizeCompleted)
        {
            // finish app if finalization has been completed
            delete data;
            break;
        }

        state_manager->HandleEvent(data);
        delete data;
    }

    delete state_manager;
    return 0;
}