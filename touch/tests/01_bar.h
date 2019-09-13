/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/t_01_bar.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>

#if SEAM == kabuki.toolkit_AV_0
#include "t_test_debug.inl"
#else
#include "t_test_release.inl"
#endif

using namespace _;

namespace kabuki {
namespace toolkit {
namespace touch {
inline const CH1* _1_Bar(CH1* seam_log, CH1* seam_end, const CH1* args) {
#if SEAM >= kabuki.toolkit_TOUCH_0
  TEST_BEGIN;
  control_array a();

  D_COUT("Testing const CH1* print (_::Expr& slot)...");
  a.Print();

  DMXControl c1("Control 1", 50, 33);
  MIDIControl c2("Control 2", 11, 102);

  D_COUT("testing void setControl  (Control*)");

  a.SetControl(0, &c1);
  a.SetControl(1, &c2);

  D_COUT("Added 2 controls to a:\n");
  a.Print();

  DMXControl c3("Control 3", 27, 66);
  MIDIControl c4("Control 4", 62, 24);

  a.AddControl(&c3);
  a.AddControl(&c4);

  D_COUT("Attempted to add 2 more controls a:\n");
  a.Print();

  DMXButton c5("Control 5", 27, 66);
  TButtonMIDI c6("Control 6", 62, 24);
  MacroButton c7("Control 7");
  c7.Add(&c1);
  c7.Add(&c2);
  c7.Add(&c3);
  c7.Add(&c4);
  c7.Add(&c5);
  c7.Add(&c6);

  a.AddControl(&c5);
  a.AddControl(&c6);
  a.AddControl(&c7);

  PRINT("Attempted to add some buttons:\n");
  a.Print();

  D_COUT("_::control_array tests completed successfully. :-)");

  D_COUT("_::DMXButton class LIB_MEMBER\n");

  DMXButton a("DMX Button A");

  D_COUT("Testing const CH1* print (_::Expr& slot)...");
  a.Print();

  D_COUT("Testing void processPress () and void processDepress ()");
  a.Press();
  CHECK(a.isPressed());
  a.Depress();
  CHECK(!a.isPressed());

  D_COUT("Testing void toggle ()");
  a.SetButtonAction(ButtonAction::Latching);
  a.Toggle();
  CHECK(a.GetValue() == a.GetMaxValue());
  a.Toggle();
  CHECK(a.GetValue() == a.GetMinValue());

  D_COUT("\n\n_Theater::ProjectTests completed.\n\n");

  D_COUT("Testing TControlMatrix class.");

  D_COUT("Testing const CH1* print (_::Expr& slot):\n");
  TControlMatrix cm(5, 2);
  cm.Print();

  D_COUT("Testing setControl ()");

  DMXControl testControl0_0("DMX Control 1");
  MIDIControl testControl1_0("MIDI Control 1");
  DMXButton testControl2_0("DMX Button 1");
  TButtonMIDI testControl3_0("MIDI Button 1");
  MacroButton testControl4_0("Macro Button 1");

  DMXControl testControl0_1("DMX Control 2");
  MIDIControl testControl1_1("MIDI Control 2");
  DMXButton testControl2_1("DMX Button 2");
  TButtonMIDI testControl3_1("MIDI Button 2");
  MacroButton testControl4_1("Macro Button 2");

  cm.SetControl(0, 0, &testControl0_0);
  cm.SetControl(1, 0, &testControl1_0);
  cm.SetControl(2, 0, &testControl2_0);
  cm.SetControl(3, 0, &testControl3_0);
  cm.SetControl(4, 0, &testControl4_0);

  cm.SetControl(0, 1, &testControl0_1);
  cm.SetControl(1, 1, &testControl1_1);
  cm.SetControl(2, 1, &testControl2_1);
  cm.SetControl(3, 1, &testControl3_1);
  cm.SetControl(4, 1, &testControl4_1);

  cm.Print();

  D_COUT("Done testing TControlMatrix class LIB_MEMBER! :-)");

  D_COUT("\n\n_Theater::ProjectTests completed.\n\n");

  D_COUT("Running TWidget tests...");

  D_COUT("Testing TWidget class LIB_MEMBER\n");
  PRINT_LINE('~');

  TWidget w("Test TWidget");

  D_COUT("Testing const CH1* ToString ()\n");

  w.Print();

  D_COUT("Testing InsertPage  (const CH1*&)\n");

  const CH1* page_name_String;
  CH1 pageIndex = '1';

  for (SI4 i = 0; i < 6; ++i) {
    page_name_String = "Page " + pageIndex;
    D_COUT("Inserting Page %s...", page_name_String);
    CHECK(!w.InsertPage(page_name_String),
          "Error: Failed to insert page " + page_name_String + "!\n");
    ++pageIndex;
  }

  D_COUT(w.ToString());

  D_COUT("Testing contains  (const CH1*&)...");

  CHECK(!w.contains("Page 1"), "Error: w does not contains \"Page 1\"");

  D_COUT("Testing DeletePage  (SI4)... ");

  SI4 debug_code;

  debug_code = w.DeletePage(1);

  CHECK(debug_code == 1,
        "Error: w.DeletePage  (1) returned invalid debug_code: " + debug_code);

  w.DeletePage(2);
  w.DeletePage(3);
  debug_code = w.DeletePage(3);
  CHECK(debug_code == 1, "Error: debugCdode was not equal to 1: " + debug_code);
  w.DeletePage(3);
  w.DeletePage(1);
  w.DeletePage(2);
  w.DeletePage(2);
  w.DeletePage(2);
  w.DeletePage(1);
  w.DeletePage(1);
  w.DeletePage(1);
  w.Print();

  D_COUT("Testing inserting duplicate page names...");

  for (SI4 i = 0; i < 5; ++i) {
    debug_code = w.InsertPage("Untitled");
    D_COUT((i + 1) + ".) Debug code: " + debug_code);
  }
  debug_code = w.InsertPage("Untitled");

  w.DeletePage("Untitled 4");
  debug_code = w.InsertPage("Untitled");

  D_COUT(w.ToString());

  D_COUT("Testing copy constructor...");
  TWidget wc(w);
  wc.Print();

  D_COUT("Done testing TWidget class LIB_MEMBER");

  D_COUT("\n\nRunning TWidget tests completed.\n\n");

  D_COUT("Testing WidgetPage");

  D_COUT("Testing Page class\n");
  PRINT_LINE('~');

  WidgetPage p("Test Page");

  D_COUT("Testing const CH1* ToString ()");
  p.Print();

  D_COUT("Testing copy constructor...");
  WidgetPage pc(p);
  pc.Print();

  D_COUT("Done testing Page class");

  D_COUT("\n\nRunning WidgetPage tests completed.\n\n");

  D_COUT("Testing MIDIControl\n");

  MIDIControl a("MIDI Control A");
  a.Print();

  D_COUT("Testing setCC ()");
  a.SetCC(127);
  CHECK(a.GetCC() == 127);
  a.SetCC(128);
  CHECK(a.GetCC() == 127);
  a.SetCC(-1);
  D_COUT("a:\n");
  a.Print();
  CHECK(a.GetCC() == 0);

  D_COUT("Done testing MIDIControl class LIB_MEMBER. :-)\n");

  D_COUT("_::TButtonMIDI...\n");

  TButtonMIDI a("MIDI Button A");

  D_COUT("Testing const CH1* print (_::Expr& slot)");
  a.Print();

  D_COUT("\n\n_Theater::TButtonMIDI tests completed.\n\n");

  D_COUT("Testing MacroButton class LIB_MEMBER:\n");

  auto macroA = MacroButton("Macro Button A");

  D_COUT("Testing const CH1* print (_::verifier&)...");
  D_COUT(macroA.Print(_::Expr & slot));
  D_COUT("Testing add  (Parameter<SI4>*)");
  macroA.add(new DMXControl("Macro 1"));
  macroA.add(new MIDIControl("Macro 2"));
  macroA.add(new DMXButton("Macro 3"));
  macroA.add(new TButtonMIDI("Macro 4"));
  D_COUT("Added " + const CH1*(macroA.numControls()) + " test controls.\n" +
         macroA.Print(_::Expr & slot));
  D_COUT("Testing void trigger ()");
  macroA.trigger();
  D_COUT("Testing Parameter<SI4>* remove  (index);");

  D_COUT("\n\n_Theater::ProjectTests completed.\n\n");

  D_COUT("_::Label Class.\n");

  const CH1 *invalid_String = "Invalid label ~",
            *valid_String_1 = "Valid label 1",
            *valid_String_2 = "Valid label !@%^",
            *valid_String_3 = "Valid label &* ()";

  Label valid_label_1(valid_String_1);
  Label valid_label_2(valid_String_1);
  Label valid_label_3(valid_String_3);
  Label invalid_label(invalid_String);

  D_COUT("Testing valid AString input.");

  D_COUT("Testing SI4 IsValid  (const CH1* &)");
  D_COUT("isValidString(valid_String_1): %b", is_valid_label(valid_String_1));
  CHECK(is_valid_label(valid_String_1) == Valid);
  D_COUT("Testing invalid AString input.");
  CHECK(is_valid_label(invalid_String) != Valid);
  CHECK(is_valid_label("") != 0);
  CHECK(is_valid_label("123456789012345678901") != 0);

  D_COUT("Testing SI4 compare  (const CH1* &)\n");
  invalid_label.Print();
  D_COUT("Testing valid comparisons...");
  CHECK(!valid_label_1.Compare(valid_String_1));
  D_COUT("Testing invalid comparisons...");
  CHECK(valid_label_1.Compare(valid_String_2) != Comperable);
  CHECK(valid_label_2.Compare(valid_String_3) != Comperable);

  D_COUT("Attempting to SetLabel to the invalid_String");
  // auto expectedLabel = "Test AString 1";
  valid_label_1.SetLabel(invalid_String);
  CHECK(!valid_label_1.Compare(invalid_label));
  D_COUT("Setting the label to valid_String_3");
  valid_label_1.SetLabel(valid_String_3);
  CHECK(valid_label_1.Label() == valid_String_3);

  D_COUT("Done testing Label class LIB_MEMBER.");

  D_COUT("\n\n_Theater::ProjectTests completed.\n\n");

  D_COUT("Testing IsymmetricController class _KabukiToolkit\n");
  PRINT_LINE('~');

  IsymmetricController controller();

  D_COUT("Testing ToString ().");
  D_COUT(controller.Print());

  // testISCS.addTemplate ();

  D_COUT("Done testing IsymmetricController class _KabukiToolkit");

  D_COUT("\n\n_Theater::ProjectTests completed.\n\n");

  D_COUT("_::DMXControl");

  PRINT_LINE('-');
  DMXControl control_a("DMX Control A");

  D_COUT("Printing control_a.Print (_::Expr& slot)\n");
  control_a.Print();

  D_COUT("Testing copy constructor\n");
  DMXControl control_b(control_a);
  D_COUT("Printing control_b.Print (_::Expr& slot)\n");
  control_b.Print();
  D_COUT("Testing SI4 Compare  (const Control&)");

  CHECK(control_a.Compare(control_b) == 0);
  SI4 compare_value = control_a.Compare(control_b);
  D_COUT("Testing SI4 Compare  (const Control&): " + compare_value);
  CHECK(compare_value == 0);

  D_COUT("Testing valid inputs...");

  control_a = DMXControl("", 1, 1, 0, 255, 8);

  D_COUT("Printing control_a.Print (_::Expr& slot)...\n");
  control_a.Print();

  control_a.SetLabel("DMX Control B");
  CHECK(control_a.label() == "DMX Control B");
  control_a.SetInitValue(35);
  control_a.Print() CHECK(control_a.initValue() == 35);
  control_a.SetLSBValue(66);
  CHECK(control_a.lSBValue() == 66);
  control_a.SetMaxValue(245);
  CHECK(control_a.maxValue() == 245);
  control_a.SetMinValue(70);
  CHECK(control_a.GetMinValue() == 70);

  D_COUT("Retesting copy constructor");

  control_b = DMXControl(control_a);
  compare_value = control_a.Compare(control_b);
  CHECK(!compare_value);

  D_COUT("Testing invalid input...");

  control_a.SetWordSize(5);
  D_COUT("control_a.WordSize (): %i\n", control_a.WordSize());
  CHECK(control_a.GetWordSize() == 7);
  control_a.SetChannel(555);
  CHECK(control_a.GetChannel() == DMXControl::NumChannels);
  control_a.SetChannel(-5);
  CHECK(control_a.GetChannel() == 0);
  control_a.SetChannel(1);
  CHECK(control_a.GetChannel() == 1);

  D_COUT("Done testing DMXControl class LIB_MEMBER");

  D_COUT("_::DMXButton class LIB_MEMBER\n");

  DMXButton a("DMX Button A");

  D_COUT("Testing const CH1* print (_::Expr& slot)...");
  a.Print();

  D_COUT("Testing void processPress () and void processDepress ()");
  a.Press();
  CHECK(a.IsPressed());
  a.Depress();
  CHECK(!a.IsPressed());

  D_COUT("Testing void toggle ()");
  a.SetButtonAction(ButtonAction::Latching);
  a.Toggle();
  CHECK(a.GetValue() == a.GetMaxValue());
  a.Toggle();
  CHECK(a.GetValue() == a.GetMinValue());

  D_COUT("\n\n_Theater::ProjectTests completed.\n\n");

#endif
  return 0;
}
}  // namespace touch
}  // namespace toolkit
}  // namespace kabuki
