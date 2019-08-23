/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /toolkit/touch/t_controlmatrix.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_CONTROLMATRIX
#define KABUKI_TOOLKIT_AV_CONTROLMATRIX

#include "t_paramset.h"

namespace _ {

/* A grid of Controls.
    Each Parameter<SI4> Layer on the Symmetry Live can either have 8 pots or
   encoders, or can have 4 pots and 4 encoders. This class LIB_MEMBER helps us swap
   the values out quickly and efficiently.

    A TControlMatrix must have the option of being bifurcated. */
class LIB_MEMBER TControlMatrix {
 public:
  enum {
    kMinNumRows = 1,                             //< The min number of rows.
    kMinNumColumns = 2,                          //< The min number of columns.
    kMaxNumRows = ParamSet::kElementCountMax,  //< The max number of rows.
    kMaxNumColumns =
        ParamSet::kElementCountMax,  //< The max number of columns.
  };

  /* Default constructor. */
  TControlMatrix(SI4 column_count = 8, SI4 num_rows = 6) {
    col_count_ = BoundRange (column_count, kMinNumColumns, kMaxNumColumns);
    num_rows = BoundRange (num_rows, kMinNumRows, kMaxNumRows);

    rows = new ParamSet[num_rows];

    for (SI4 i = 0; i < num_rows; ++i) rows[i] = ParamSet (column_count);
  }

  /* Copy constructor. */
  TControlMatrix(const TControlMatrix& o)
    : row_count_ (o.row_count_), col_count_ (o.col_count_) {
    rows = new ParamSet (row_count_);
  }

  /* Virtual Destructor. */
  virtual ~TControlMatrix () {}

  /* Gets the number of rows. */
  SI4 GetNumRows() const { return row_count_; }

  /* Gets the number of columns. */
  SI4 GetNumColumns() const { return col_count_; }

  /* Sets the pointer to knobs[index] pointer to the newKnob. */
  void SetParameter(SI4 column, SI4 row, Parameter<SI4>* control) {
    if (row < 0 || column < 0 || row >= row_count_ || column >= col_count_)
      return;
    rows[row].SetControl (column, control);
  }

  /* Gets the row at the given index.
  @return gets nullptr if the index is invalid. */
  ParamSet* GetRow(SI4 row) {
    if (row < 0 || row >= row_count_) return nullptr;
    return rows[row];
  }

  /* Prints this object to a AString. */
  template<typename Printer>
  Printer& Print(Printer& o) const {
    o << LineStrand ('-', Parameter<SI4>::kMacroHeaderLength)
      << "Control Grid: rows:" << row_count_
      << " columns:" << col_count_
      << LineStrand('-', Parameter<SI4>::kMacroHeaderLength);
    PrintMacroHeader (o);
    o << LineStrand ('-', Parameter<SI4>::kMacroHeaderLength)
      << "\n!!!!row_count_" << row_count_;

    for (SI4 i = 0; i < row_count_; ++i) {
      o << "Row:" << i;
      rows[i].Print (o);
    }

    return o << LineStrand ('-', Parameter<SI4>::kMacroHeaderLength);
  }

 private:
  SI4 row_count_,       //< Number of rows.
      col_count_;       //< Number of columns.
  ParamSet* rows_;  //< Rows of control array columns.
};
}  // namespace _
#endif
#endif
