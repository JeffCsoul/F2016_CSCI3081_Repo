/*******************************************************************************
 * Name            : mia_cmd.cc
 * Project         : MIA
 * Module          : App
 * Description     : Implementation of MIACmd
 * Copyright       : 2016 CSCI3081W Group A01. all rights reserved.
 * Creation Date   : 12/06/2016
 * Original Author : CSCI3081W Group A01
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/mia_cmd.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <stack>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MIACmd::MIACmd(void) : filename_({}),
                       parseresult_(0),
                       sharpen_(false),
                       sharpen_amount_(0),
                       edge_(false),
                       threshold_(false),
                       threshold_amount_(0),
                       quantize_(false),
                       quantize_bin_(2),
                       blur_(false),
                       blur_amount_(0),
                       saturate_(false),
                       saturate_amount_(0),
                       channel_(false),
                       channel_red_(0),
                       channel_green_(0),
                       channel_blue_(0) {

}

MIACmd::MIACmd(int argc, char *argv[]) {
  MIACmd::MIACmd();
  std::vector <std::string> argstr;
  argstr.clear();
  if (argc == 1) {
    this->parseresult_ = NO_CMD_LINES;
    return;
  }
  for (int i = 1; i < argc; i++)
    argstr.push_back(std::string(argv[i]));
  for (unsigned long i = 0; i < argstr.size(); i++) {
    if (argstr[i] == "-h") {
      this->parseresult_ = HELP_MESSAGE;
      return;
    }
    if (argstr[i] == "-compare") {
      if (argstr.size() == 3 && i == 1) {
        this->parseresult_ = COMPARE_IMG;
        this->filename_.push_back(make_pair(argstr[0], argstr[2]));
        return;
      } else {
        this->parseresult_ = CMD_ERROR;
        return;
      }
    }
  }
  std::size_t numofinsign, numofoutsign;
  numofinsign = std::count(argstr[0].begin(), argstr[0].end(), '#');
  numofoutsign = std::count(argstr[argstr.size() - 1].begin(),
                            argstr[argstr.size() - 1].end(),
                            '#');
  if (numofinsign != numofoutsign) {
    this->parseresult_ = FILE_ERROR;
    return;
  }

  GenFileNamePair(argstr[0], argstr[argstr.size() - 1], numofinsign);

  for (unsigned long i = 1; i < argstr.size() - 1; i++) {

    try {
      // bitset constructor throws an invalid_argument if initialized
    }
    catch (const std::invalid_argument& ia) {
    }

  }
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void MIACmd::GenFileNamePair(std::string infilename,
                        std::string outfilename,
                        int rest_sign) {
  if (rest_sign == 0) {
    this->filename_.push_back(make_pair(infilename, outfilename));
    return;
  }
}

}  /* namespace image_tools */
