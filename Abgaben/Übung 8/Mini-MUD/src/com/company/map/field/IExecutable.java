package com.company.map.field;

import com.company.Player;
import com.company.enums.ActionFunctions;

public interface IExecutable {
    void execute(Player player, ActionFunctions actionFunctions);
}
