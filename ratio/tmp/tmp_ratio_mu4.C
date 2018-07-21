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

using namespace std;


void tmp_ratio_mu4(){

  gROOT -> SetStyle("Plain");

  //Root File
  ///95
  TFile *data18_95_Jpsi_all    = new TFile("/gpfs/fs2001/yfukuhar/tmp/CalcEffPlotMakerOrigin/outroot/hadd_data18_v3_mu26ivm_ok/data18_349533_jpsi_all.root");
  TFile *data18_95_Jpsi_barrel = new TFile("/gpfs/fs2001/yfukuhar/tmp/CalcEffPlotMakerOrigin/outroot/hadd_data18_v3_mu26ivm_ok/data18_349533_jpsi_barrel.root");
  TFile *data18_95_Jpsi_endcap = new TFile("/gpfs/fs2001/yfukuhar/tmp/CalcEffPlotMakerOrigin/outroot/hadd_data18_v3_mu26ivm_ok/data18_349533_jpsi_endcap.root");
  ///91
  TFile *data18_91_Jpsi_all    = new TFile("/gpfs/fs2001/yfukuhar/tmp/CalcEffPlotMakerOrigin/outroot/hadd_data18_v3_mu26ivm_ok/data18_349014_jpsi_all.root");
  TFile *data18_91_Jpsi_barrel = new TFile("/gpfs/fs2001/yfukuhar/tmp/CalcEffPlotMakerOrigin/outroot/hadd_data18_v3_mu26ivm_ok/data18_349014_jpsi_barrel.root");
  TFile *data18_91_Jpsi_endcap = new TFile("/gpfs/fs2001/yfukuhar/tmp/CalcEffPlotMakerOrigin/outroot/hadd_data18_v3_mu26ivm_ok/data18_349014_jpsi_endcap.root");

  //Hist of data and mc

  ///mu4, pt, all, TOTAL_2
  TH1F *h_data_mu4_pt_all          = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_pt_mu4_TOTAL_2");
  TH1F *h_mc_mu4_pt_all            = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_pt_mu4_TOTAL_2");
  ///mu4, pt, barrel
  TH1F *h_data_mu4_pt_barrel       = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_pt_mu4_TOTAL_2");
  TH1F *h_mc_mu4_pt_barrel         = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_pt_mu4_TOTAL_2");
  ///mu4, pt, endcap
  TH1F *h_data_mu4_pt_endcap       = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_pt_mu4_TOTAL_2");
  TH1F *h_mc_mu4_pt_endcap         = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_pt_mu4_TOTAL_2");

  ///mu4, pt, all, L1
  TH1F *h_data_mu4_pt_all_L1       = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_pt_mu4_L1");
  TH1F *h_mc_mu4_pt_all_L1         = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_pt_mu4_L1");
  ///mu4, pt, barrel
  TH1F *h_data_mu4_pt_barrel_L1    = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_pt_mu4_L1");
  TH1F *h_mc_mu4_pt_barrel_L1      = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_pt_mu4_L1");
  ///mu4, pt, endcap
  TH1F *h_data_mu4_pt_endcap_L1    = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_pt_mu4_L1");
  TH1F *h_mc_mu4_pt_endcap_L1      = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_pt_mu4_L1");

  ///mu4, pt, all, L1SA
  TH1F *h_data_mu4_pt_all_L1SA     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_pt_mu4_L1SA");
  TH1F *h_mc_mu4_pt_all_L1SA       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_pt_mu4_L1SA");
  ///mu4, pt, barrel
  TH1F *h_data_mu4_pt_barrel_L1SA  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_pt_mu4_L1SA");
  TH1F *h_mc_mu4_pt_barrel_L1SA    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_pt_mu4_L1SA");
  ///mu4, pt, endcap
  TH1F *h_data_mu4_pt_endcap_L1SA  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_pt_mu4_L1SA");
  TH1F *h_mc_mu4_pt_endcap_L1SA    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_pt_mu4_L1SA");

  ///mu4, pt, all, SACB
  TH1F *h_data_mu4_pt_all_SACB     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_pt_mu4_SACB");
  TH1F *h_mc_mu4_pt_all_SACB       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_pt_mu4_SACB");
  ///mu4, pt, barrel
  TH1F *h_data_mu4_pt_barrel_SACB  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_pt_mu4_SACB");
  TH1F *h_mc_mu4_pt_barrel_SACB    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_pt_mu4_SACB");
  ///mu4, pt, endcap
  TH1F *h_data_mu4_pt_endcap_SACB  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_pt_mu4_SACB");
  TH1F *h_mc_mu4_pt_endcap_SACB    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_pt_mu4_SACB");

  ///mu4, pt, all, CBEF
  TH1F *h_data_mu4_pt_all_CBEF     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_pt_mu4_L2EF");
  TH1F *h_mc_mu4_pt_all_CBEF       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_pt_mu4_L2EF");
  ///mu4, pt, barrel
  TH1F *h_data_mu4_pt_barrel_CBEF  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_pt_mu4_L2EF");
  TH1F *h_mc_mu4_pt_barrel_CBEF    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_pt_mu4_L2EF");
  ///mu4, pt, endcap
  TH1F *h_data_mu4_pt_endcap_CBEF  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_pt_mu4_L2EF");
  TH1F *h_mc_mu4_pt_endcap_CBEF    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_pt_mu4_L2EF");

  ///mu4, phi, all, TOTAL_2
  TH1F *h_data_mu4_phi_all          = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_phi_mu4_TOTAL_2");
  TH1F *h_mc_mu4_phi_all            = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_phi_mu4_TOTAL_2");
  ///mu4, phi, barrel
  TH1F *h_data_mu4_phi_barrel       = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_phi_mu4_TOTAL_2");
  TH1F *h_mc_mu4_phi_barrel         = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_phi_mu4_TOTAL_2");
  ///mu4, phi, endcap
  TH1F *h_data_mu4_phi_endcap       = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_phi_mu4_TOTAL_2");
  TH1F *h_mc_mu4_phi_endcap         = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_phi_mu4_TOTAL_2");

  ///mu4, phi, all, L1
  TH1F *h_data_mu4_phi_all_L1       = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_phi_mu4_L1");
  TH1F *h_mc_mu4_phi_all_L1         = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_phi_mu4_L1");
  ///mu4, phi, barrel
  TH1F *h_data_mu4_phi_barrel_L1    = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_phi_mu4_L1");
  TH1F *h_mc_mu4_phi_barrel_L1      = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_phi_mu4_L1");
  ///mu4, phi, endcap
  TH1F *h_data_mu4_phi_endcap_L1    = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_phi_mu4_L1");
  TH1F *h_mc_mu4_phi_endcap_L1      = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_phi_mu4_L1");

  ///mu4, phi, all, L1SA
  TH1F *h_data_mu4_phi_all_L1SA     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_phi_mu4_L1SA");
  TH1F *h_mc_mu4_phi_all_L1SA       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_phi_mu4_L1SA");
  ///mu4, phi, barrel
  TH1F *h_data_mu4_phi_barrel_L1SA  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_phi_mu4_L1SA");
  TH1F *h_mc_mu4_phi_barrel_L1SA    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_phi_mu4_L1SA");
  ///mu4, phi, endcap
  TH1F *h_data_mu4_phi_endcap_L1SA  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_phi_mu4_L1SA");
  TH1F *h_mc_mu4_phi_endcap_L1SA    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_phi_mu4_L1SA");

  ///mu4, phi, all, SACB
  TH1F *h_data_mu4_phi_all_SACB     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_phi_mu4_SACB");
  TH1F *h_mc_mu4_phi_all_SACB       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_phi_mu4_SACB");
  ///mu4, phi, barrel
  TH1F *h_data_mu4_phi_barrel_SACB  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_phi_mu4_SACB");
  TH1F *h_mc_mu4_phi_barrel_SACB    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_phi_mu4_SACB");
  ///mu4, phi, endcap
  TH1F *h_data_mu4_phi_endcap_SACB  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_phi_mu4_SACB");
  TH1F *h_mc_mu4_phi_endcap_SACB    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_phi_mu4_SACB");

  ///mu4, phi, all, CBEF
  TH1F *h_data_mu4_phi_all_CBEF     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_phi_mu4_L2EF");
  TH1F *h_mc_mu4_phi_all_CBEF       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_phi_mu4_L2EF");
  ///mu4, phi, barrel
  TH1F *h_data_mu4_phi_barrel_CBEF  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_phi_mu4_L2EF");
  TH1F *h_mc_mu4_phi_barrel_CBEF    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_phi_mu4_L2EF");
  ///mu4, phi, endcap
  TH1F *h_data_mu4_phi_endcap_CBEF  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_phi_mu4_L2EF");
  TH1F *h_mc_mu4_phi_endcap_CBEF    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_phi_mu4_L2EF");

  ///mu4, eta, all, TOTAL_2
  TH1F *h_data_mu4_eta_all          = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_eta_mu4_TOTAL_2");
  TH1F *h_mc_mu4_eta_all            = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_eta_mu4_TOTAL_2");
  ///mu4, eta, barrel
  TH1F *h_data_mu4_eta_barrel       = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_eta_mu4_TOTAL_2");
  TH1F *h_mc_mu4_eta_barrel         = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_eta_mu4_TOTAL_2");
  ///mu4, eta, endcap
  TH1F *h_data_mu4_eta_endcap       = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_eta_mu4_TOTAL_2");
  TH1F *h_mc_mu4_eta_endcap         = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_eta_mu4_TOTAL_2");

  ///mu4, eta, all, L1
  TH1F *h_data_mu4_eta_all_L1       = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_eta_mu4_L1");
  TH1F *h_mc_mu4_eta_all_L1         = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_eta_mu4_L1");
  ///mu4, eta, barrel
  TH1F *h_data_mu4_eta_barrel_L1    = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_eta_mu4_L1");
  TH1F *h_mc_mu4_eta_barrel_L1      = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_eta_mu4_L1");
  ///mu4, eta, endcap
  TH1F *h_data_mu4_eta_endcap_L1    = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_eta_mu4_L1");
  TH1F *h_mc_mu4_eta_endcap_L1      = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_eta_mu4_L1");

  ///mu4, eta, all, L1SA
  TH1F *h_data_mu4_eta_all_L1SA     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_eta_mu4_L1SA");
  TH1F *h_mc_mu4_eta_all_L1SA       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_eta_mu4_L1SA");
  ///mu4, eta, barrel
  TH1F *h_data_mu4_eta_barrel_L1SA  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_eta_mu4_L1SA");
  TH1F *h_mc_mu4_eta_barrel_L1SA    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_eta_mu4_L1SA");
  ///mu4, eta, endcap
  TH1F *h_data_mu4_eta_endcap_L1SA  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_eta_mu4_L1SA");
  TH1F *h_mc_mu4_eta_endcap_L1SA    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_eta_mu4_L1SA");

  ///mu4, eta, all, SACB
  TH1F *h_data_mu4_eta_all_SACB     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_eta_mu4_SACB");
  TH1F *h_mc_mu4_eta_all_SACB       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_eta_mu4_SACB");
  ///mu4, eta, barrel
  TH1F *h_data_mu4_eta_barrel_SACB  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_eta_mu4_SACB");
  TH1F *h_mc_mu4_eta_barrel_SACB    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_eta_mu4_SACB");
  ///mu4, eta, endcap
  TH1F *h_data_mu4_eta_endcap_SACB  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_eta_mu4_SACB");
  TH1F *h_mc_mu4_eta_endcap_SACB    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_eta_mu4_SACB");

  ///mu4, eta, all, CBEF
  TH1F *h_data_mu4_eta_all_CBEF     = (TH1F*)data18_95_Jpsi_all    -> Get("h_eff_eta_mu4_L2EF");
  TH1F *h_mc_mu4_eta_all_CBEF       = (TH1F*)data18_91_Jpsi_all      -> Get("h_eff_eta_mu4_L2EF");
  ///mu4, eta, barrel
  TH1F *h_data_mu4_eta_barrel_CBEF  = (TH1F*)data18_95_Jpsi_barrel -> Get("h_eff_eta_mu4_L2EF");
  TH1F *h_mc_mu4_eta_barrel_CBEF    = (TH1F*)data18_91_Jpsi_barrel   -> Get("h_eff_eta_mu4_L2EF");
  ///mu4, eta, endcap
  TH1F *h_data_mu4_eta_endcap_CBEF  = (TH1F*)data18_95_Jpsi_endcap -> Get("h_eff_eta_mu4_L2EF");
  TH1F *h_mc_mu4_eta_endcap_CBEF    = (TH1F*)data18_91_Jpsi_endcap   -> Get("h_eff_eta_mu4_L2EF");




  //PDF_NAME
  TString pdf_mu4_pt  = "./output/data18_ratio_mu4_pt.pdf";
  TString pdf_mu4_phi = "./output/data18_ratio_mu4_phi.pdf";
  TString pdf_mu4_eta = "./output/data18_ratio_mu4_eta.pdf";
 
  //mu4,pt========================================
  //mu4, pt, all_TOTAL----------------------------------------------------------------
  TCanvas *caPt = new TCanvas("caPt","caPt",1000,720);
  MainProcess(caPt, h_data_mu4_pt_all, h_mc_mu4_pt_all, "all_TOTAL", pdf_mu4_pt + "(");
  caPt->Close();

  //mu4, pt, barrel_TOTAL----------------------------------------------------------------
  TCanvas *cbPt = new TCanvas("cbPt","cbPt",1000,720);
  MainProcess(cbPt, h_data_mu4_pt_barrel, h_mc_mu4_pt_barrel, "barrel_TOTAL", pdf_mu4_pt);
  cbPt->Close();

  //mu4, pt, endcap_TOTAL----------------------------------------------------------------
  TCanvas *cePt = new TCanvas("cePt","cePt",1000,720);
  MainProcess(cePt, h_data_mu4_pt_endcap, h_mc_mu4_pt_endcap, "endcap_TOTAL", pdf_mu4_pt);
  cePt->Close();

  //mu4, pt, all_L1----------------------------------------------------------------
  TCanvas *caPt = new TCanvas("caPt","caPt",1000,720);
  MainProcess(caPt, h_data_mu4_pt_all_L1, h_mc_mu4_pt_all_L1, "all_L1", pdf_mu4_pt);
  caPt->Close();

  //mu4, pt, barrel_L1----------------------------------------------------------------
  TCanvas *cbPt = new TCanvas("cbPt","cbPt",1000,720);
  MainProcess(cbPt, h_data_mu4_pt_barrel_L1, h_mc_mu4_pt_barrel_L1, "barrel_L1", pdf_mu4_pt);
  cbPt->Close();

  //mu4, pt, endcap_L1----------------------------------------------------------------
  TCanvas *cePt = new TCanvas("cePt","cePt",1000,720);
  MainProcess(cePt, h_data_mu4_pt_endcap_L1, h_mc_mu4_pt_endcap_L1, "endcap_L1", pdf_mu4_pt);
  cePt->Close();

  //mu4, pt, all_L1SA----------------------------------------------------------------
  TCanvas *caPt = new TCanvas("caPt","caPt",1000,720);
  MainProcess(caPt, h_data_mu4_pt_all_L1SA, h_mc_mu4_pt_all_L1SA, "all_L1SA", pdf_mu4_pt);
  caPt->Close();

  //mu4, pt, barrel_L1SA----------------------------------------------------------------
  TCanvas *cbPt = new TCanvas("cbPt","cbPt",1000,720);
  MainProcess(cbPt, h_data_mu4_pt_barrel_L1SA, h_mc_mu4_pt_barrel_L1SA, "barrel_L1SA", pdf_mu4_pt);
  cbPt->Close();

  //mu4, pt, endcap_L1SA----------------------------------------------------------------
  TCanvas *cePt = new TCanvas("cePt","cePt",1000,720);
  MainProcess(cePt, h_data_mu4_pt_endcap_L1SA, h_mc_mu4_pt_endcap_L1SA, "endcap_L1SA", pdf_mu4_pt);
  cePt->Close();

  //mu4, pt, all_SACB----------------------------------------------------------------
  TCanvas *caPt = new TCanvas("caPt","caPt",1000,720);
  MainProcess(caPt, h_data_mu4_pt_all_SACB, h_mc_mu4_pt_all_SACB, "all_SACB", pdf_mu4_pt);
  caPt->Close();

  //mu4, pt, barrel_SACB----------------------------------------------------------------
  TCanvas *cbPt = new TCanvas("cbPt","cbPt",1000,720);
  MainProcess(cbPt, h_data_mu4_pt_barrel_SACB, h_mc_mu4_pt_barrel_SACB, "barrel_SACB", pdf_mu4_pt);
  cbPt->Close();

  //mu4, pt, endcap_SACB----------------------------------------------------------------
  TCanvas *cePt = new TCanvas("cePt","cePt",1000,720);
  MainProcess(cePt, h_data_mu4_pt_endcap_SACB, h_mc_mu4_pt_endcap_SACB, "endcap_SACB", pdf_mu4_pt);
  cePt->Close();

  //mu4, pt, all_CBEF----------------------------------------------------------------
  TCanvas *caPt = new TCanvas("caPt","caPt",1000,720);
  MainProcess(caPt, h_data_mu4_pt_all_CBEF, h_mc_mu4_pt_all_CBEF, "all_CBEF", pdf_mu4_pt);
  caPt->Close();

  //mu4, pt, barrel_CBEF----------------------------------------------------------------
  TCanvas *cbPt = new TCanvas("cbPt","cbPt",1000,720);
  MainProcess(cbPt, h_data_mu4_pt_barrel_CBEF, h_mc_mu4_pt_barrel_CBEF, "barrel_CBEF", pdf_mu4_pt);
  cbPt->Close();

  //mu4, pt, endcap_CBEF----------------------------------------------------------------
  TCanvas *cePt = new TCanvas("cePt","cePt",1000,720);
  MainProcess(cePt, h_data_mu4_pt_endcap_CBEF, h_mc_mu4_pt_endcap_CBEF, "endcap_CBEF", pdf_mu4_pt + ")");
  cePt->Close();

  //mu4,phi========================================
  //mu4, phi, all_TOTAL----------------------------------------------------------------
  TCanvas *caphi = new TCanvas("caphi","caphi",1000,720);
  MainProcess(caphi, h_data_mu4_phi_all, h_mc_mu4_phi_all, "all_TOTAL", pdf_mu4_phi + "(");
  caphi->Close();

  //mu4, phi, barrel_TOTAL----------------------------------------------------------------
  TCanvas *cbphi = new TCanvas("cbphi","cbphi",1000,720);
  MainProcess(cbphi, h_data_mu4_phi_barrel, h_mc_mu4_phi_barrel, "barrel_TOTAL", pdf_mu4_phi);
  cbphi->Close();

  //mu4, phi, endcap_TOTAL----------------------------------------------------------------
  TCanvas *cephi = new TCanvas("cephi","cephi",1000,720);
  MainProcess(cephi, h_data_mu4_phi_endcap, h_mc_mu4_phi_endcap, "endcap_TOTAL", pdf_mu4_phi);
  cephi->Close();

  //mu4, phi, all_L1----------------------------------------------------------------
  TCanvas *caphi = new TCanvas("caphi","caphi",1000,720);
  MainProcess(caphi, h_data_mu4_phi_all_L1, h_mc_mu4_phi_all_L1, "all_L1", pdf_mu4_phi);
  caphi->Close();

  //mu4, phi, barrel_L1----------------------------------------------------------------
  TCanvas *cbphi = new TCanvas("cbphi","cbphi",1000,720);
  MainProcess(cbphi, h_data_mu4_phi_barrel_L1, h_mc_mu4_phi_barrel_L1, "barrel_L1", pdf_mu4_phi);
  cbphi->Close();

  //mu4, phi, endcap_L1----------------------------------------------------------------
  TCanvas *cephi = new TCanvas("cephi","cephi",1000,720);
  MainProcess(cephi, h_data_mu4_phi_endcap_L1, h_mc_mu4_phi_endcap_L1, "endcap_L1", pdf_mu4_phi);
  cephi->Close();

  //mu4, phi, all_L1SA----------------------------------------------------------------
  TCanvas *caphi = new TCanvas("caphi","caphi",1000,720);
  MainProcess(caphi, h_data_mu4_phi_all_L1SA, h_mc_mu4_phi_all_L1SA, "all_L1SA", pdf_mu4_phi);
  caphi->Close();

  //mu4, phi, barrel_L1SA----------------------------------------------------------------
  TCanvas *cbphi = new TCanvas("cbphi","cbphi",1000,720);
  MainProcess(cbphi, h_data_mu4_phi_barrel_L1SA, h_mc_mu4_phi_barrel_L1SA, "barrel_L1SA", pdf_mu4_phi);
  cbphi->Close();

  //mu4, phi, endcap_L1SA----------------------------------------------------------------
  TCanvas *cephi = new TCanvas("cephi","cephi",1000,720);
  MainProcess(cephi, h_data_mu4_phi_endcap_L1SA, h_mc_mu4_phi_endcap_L1SA, "endcap_L1SA", pdf_mu4_phi);
  cephi->Close();

  //mu4, phi, all_SACB----------------------------------------------------------------
  TCanvas *caphi = new TCanvas("caphi","caphi",1000,720);
  MainProcess(caphi, h_data_mu4_phi_all_SACB, h_mc_mu4_phi_all_SACB, "all_SACB", pdf_mu4_phi);
  caphi->Close();

  //mu4, phi, barrel_SACB----------------------------------------------------------------
  TCanvas *cbphi = new TCanvas("cbphi","cbphi",1000,720);
  MainProcess(cbphi, h_data_mu4_phi_barrel_SACB, h_mc_mu4_phi_barrel_SACB, "barrel_SACB", pdf_mu4_phi);
  cbphi->Close();

  //mu4, phi, endcap_SACB----------------------------------------------------------------
  TCanvas *cephi = new TCanvas("cephi","cephi",1000,720);
  MainProcess(cephi, h_data_mu4_phi_endcap_SACB, h_mc_mu4_phi_endcap_SACB, "endcap_SACB", pdf_mu4_phi);
  cephi->Close();

  //mu4, phi, all_CBEF----------------------------------------------------------------
  TCanvas *caphi = new TCanvas("caphi","caphi",1000,720);
  MainProcess(caphi, h_data_mu4_phi_all_CBEF, h_mc_mu4_phi_all_CBEF, "all_CBEF", pdf_mu4_phi);
  caphi->Close();

  //mu4, phi, barrel_CBEF----------------------------------------------------------------
  TCanvas *cbphi = new TCanvas("cbphi","cbphi",1000,720);
  MainProcess(cbphi, h_data_mu4_phi_barrel_CBEF, h_mc_mu4_phi_barrel_CBEF, "barrel_CBEF", pdf_mu4_phi);
  cbphi->Close();

  //mu4, phi, endcap_CBEF----------------------------------------------------------------
  TCanvas *cephi = new TCanvas("cephi","cephi",1000,720);
  MainProcess(cephi, h_data_mu4_phi_endcap_CBEF, h_mc_mu4_phi_endcap_CBEF, "endcap_CBEF", pdf_mu4_phi + ")");
  cephi->Close();


  //mu4,eta========================================
  //mu4, eta, all_TOTAL----------------------------------------------------------------
  TCanvas *caeta = new TCanvas("caeta","caeta",1000,720);
  MainProcess(caeta, h_data_mu4_eta_all, h_mc_mu4_eta_all, "all_TOTAL", pdf_mu4_eta + "(");
  caeta->Close();

  //mu4, eta, barrel_TOTAL----------------------------------------------------------------
  TCanvas *cbeta = new TCanvas("cbeta","cbeta",1000,720);
  MainProcess(cbeta, h_data_mu4_eta_barrel, h_mc_mu4_eta_barrel, "barrel_TOTAL", pdf_mu4_eta);
  cbeta->Close();

  //mu4, eta, endcap_TOTAL----------------------------------------------------------------
  TCanvas *ceeta = new TCanvas("ceeta","ceeta",1000,720);
  MainProcess(ceeta, h_data_mu4_eta_endcap, h_mc_mu4_eta_endcap, "endcap_TOTAL", pdf_mu4_eta);
  ceeta->Close();

  //mu4, eta, all_L1----------------------------------------------------------------
  TCanvas *caeta = new TCanvas("caeta","caeta",1000,720);
  MainProcess(caeta, h_data_mu4_eta_all_L1, h_mc_mu4_eta_all_L1, "all_L1", pdf_mu4_eta);
  caeta->Close();

  //mu4, eta, barrel_L1----------------------------------------------------------------
  TCanvas *cbeta = new TCanvas("cbeta","cbeta",1000,720);
  MainProcess(cbeta, h_data_mu4_eta_barrel_L1, h_mc_mu4_eta_barrel_L1, "barrel_L1", pdf_mu4_eta);
  cbeta->Close();

  //mu4, eta, endcap_L1----------------------------------------------------------------
  TCanvas *ceeta = new TCanvas("ceeta","ceeta",1000,720);
  MainProcess(ceeta, h_data_mu4_eta_endcap_L1, h_mc_mu4_eta_endcap_L1, "endcap_L1", pdf_mu4_eta);
  ceeta->Close();

  //mu4, eta, all_L1SA----------------------------------------------------------------
  TCanvas *caeta = new TCanvas("caeta","caeta",1000,720);
  MainProcess(caeta, h_data_mu4_eta_all_L1SA, h_mc_mu4_eta_all_L1SA, "all_L1SA", pdf_mu4_eta);
  caeta->Close();

  //mu4, eta, barrel_L1SA----------------------------------------------------------------
  TCanvas *cbeta = new TCanvas("cbeta","cbeta",1000,720);
  MainProcess(cbeta, h_data_mu4_eta_barrel_L1SA, h_mc_mu4_eta_barrel_L1SA, "barrel_L1SA", pdf_mu4_eta);
  cbeta->Close();

  //mu4, eta, endcap_L1SA----------------------------------------------------------------
  TCanvas *ceeta = new TCanvas("ceeta","ceeta",1000,720);
  MainProcess(ceeta, h_data_mu4_eta_endcap_L1SA, h_mc_mu4_eta_endcap_L1SA, "endcap_L1SA", pdf_mu4_eta);
  ceeta->Close();

  //mu4, eta, all_SACB----------------------------------------------------------------
  TCanvas *caeta = new TCanvas("caeta","caeta",1000,720);
  MainProcess(caeta, h_data_mu4_eta_all_SACB, h_mc_mu4_eta_all_SACB, "all_SACB", pdf_mu4_eta);
  caeta->Close();

  //mu4, eta, barrel_SACB----------------------------------------------------------------
  TCanvas *cbeta = new TCanvas("cbeta","cbeta",1000,720);
  MainProcess(cbeta, h_data_mu4_eta_barrel_SACB, h_mc_mu4_eta_barrel_SACB, "barrel_SACB", pdf_mu4_eta);
  cbeta->Close();

  //mu4, eta, endcap_SACB----------------------------------------------------------------
  TCanvas *ceeta = new TCanvas("ceeta","ceeta",1000,720);
  MainProcess(ceeta, h_data_mu4_eta_endcap_SACB, h_mc_mu4_eta_endcap_SACB, "endcap_SACB", pdf_mu4_eta);
  ceeta->Close();

  //mu4, eta, all_CBEF----------------------------------------------------------------
  TCanvas *caeta = new TCanvas("caeta","caeta",1000,720);
  MainProcess(caeta, h_data_mu4_eta_all_CBEF, h_mc_mu4_eta_all_CBEF, "all_CBEF", pdf_mu4_eta);
  caeta->Close();

  //mu4, eta, barrel_CBEF----------------------------------------------------------------
  TCanvas *cbeta = new TCanvas("cbeta","cbeta",1000,720);
  MainProcess(cbeta, h_data_mu4_eta_barrel_CBEF, h_mc_mu4_eta_barrel_CBEF, "barrel_CBEF", pdf_mu4_eta);
  cbeta->Close();

  //mu4, eta, endcap_CBEF----------------------------------------------------------------
  TCanvas *ceeta = new TCanvas("ceeta","ceeta",1000,720);
  MainProcess(ceeta, h_data_mu4_eta_endcap_CBEF, h_mc_mu4_eta_endcap_CBEF, "endcap_CBEF", pdf_mu4_eta + ")");
  ceeta->Close();





  //complete message
  std::cout << "=== complete ===" << std::endl;

  gROOT -> ProcessLine(".q");

}
