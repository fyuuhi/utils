#include "TH1F.h"
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
#include "setup.C"
#include "rootlogon.C"

using namespace std;


void tmp_ratio_mu4(TString name_file_bunshi, TString name_file_bunbo, TString name_hist_bunshi, TString name_hist_bunbo, TString name_pdf, TString name_legend_bunshi, TString name_legend_bunbo){

  rootlogon();
  gStyle->SetLegendBorderSize(0);

  //Root File
  TFile *file_bunshi = new TFile(name_file_bunshi);
  TFile *file_bunbo  = new TFile(name_file_bunbo);

  //Histgrams
  TH1F *h_bunshi = (TH1F*)file_bunshi -> Get(name_hist_bunshi);
  TH1F *h_bunbo  = (TH1F*)file_bunbo  -> Get(name_hist_bunbo);

  //PDF_NAME
  TString pdf  = name_pdf;

  TCanvas *c1 = new TCanvas("c1","c1",1000,720);
  c1->SetGrid();

  c1 -> Print(pdf + "[", "pdf");
 
  c1 -> Print(pdf, "pdf");

  MainProcess(c1, h_bunshi, h_bunbo, "", pdf, name_legend_bunshi, name_legend_bunbo);

  c1 -> Print(pdf + "]", "pdf");


  c1->Close();

  gROOT -> ProcessLine(".q");

}
