/* Copyright 2023 @ Keychron(https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 23

/* Combo mods */
#define EXTRA_SHORT_COMBOS          // maybe save memory
#define COMBO_TERM 15               // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS        // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 100         // how long at least one of the combo keys must be held to trigger
#define COMBO_ONLY_FROM_LAYER 0     // combo keys are always checked from layer 0, even if other layers are active.
