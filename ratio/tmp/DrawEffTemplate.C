#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TMath.h"
#include "TString.h"
#include "TColor.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TApplication.h"
#include "TPaveText.h"
#include "TText.h"
#include "TLatex.h"
#include <vector>
#include <iostream>


void SetCanvas();

using namespace std;

void DrawEffTemplate(){
  TColor::InvertPalette();
  SetCanvas();
}

void SetCanvas(){
  //Set Canvas
  TCanvas *c1 = new TCanvas("c1", "c1", 10, 10, 1020, 700);
  c1     -> SetRightMargin(0.20);
  c1     -> SetLeftMargin(0.23);
  c1     -> SetBottomMargin(0.20);
  gStyle -> SetPadGridX(1);
  gStyle -> SetPadGridY(1);
  gPad   -> SetGridx(1);
  gPad   -> SetGridy(1);
}

