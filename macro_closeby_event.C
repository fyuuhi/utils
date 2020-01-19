#include <iostream>
#include <fstream>
#include <string>

#include <TStyle.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TPaveStats.h>
#include <TFile.h>

#include "/gpfs/home/youhei/atlasstyle-00-03-05/AtlasUtils.C"
#include "/gpfs/home/youhei/atlasstyle-00-03-05/AtlasStyle.C"

void macro_closeby_event(string TrigChain="mu4", TString epsdir="") {
  TString pdf = "temp.pdf";

  // TString filename = "run/test.root";
  // TString filename = "~/L2MuonSA/dataset/calceff_ntuple/Jpsi_mu3p5mu3p5_NoTag_noDR.root";
  //TString filename = "~youhei/L2MuonSA/dataset/calceff_ntuple/Jpsi_mu3p5mu3p5_NoTag_noDR_RoInumCut.root";
  //TString filename = "/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/FTK_424103_50.root";
  TString filename = "/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/FTK_424100_200.root";
  // TString filename = "~/L2MuonSA/dataset/calceff_ntuple/Jpsi_default1k_NoTag_roiWord.root";

  SetAtlasStyle();
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetPalette(1,0);
  gStyle->SetHistLineColor(1);
  gStyle->SetEndErrorSize(2);

  Color_t col0_dR = kAzure+1;
  Color_t col1_dR = kViolet+1;
  Color_t col2_dR = kPink+1;
  Color_t col3_dR = kOrange+1;

  Color_t col01_dR = kViolet-6;
  Color_t col12_dR = kPink+9;
  Color_t col23_dR = kOrange+7;
  Color_t col14_dR = kAzure-3;
  Color_t col05_dR = kGreen+1;
  Color_t col56_dR = kOrange;

  TFile* ifile = TFile::Open(filename);
  TTree* tree = (TTree*)ifile->Get("t_tap");

  int mes_n;
  vector < string >* mes_name;
  int tag_proc;
  double tag_dRL1;
  double tag_pt;
  double tag_eta;
  double tag_exteta;
  double tag_extinneta;
  double tag_phi;
  double tag_extphi;
  double tag_extinnphi;
  double tag_charge;
  double tag_L1_pt;
  double tag_L1_eta;
  double tag_L1_phi;
  double tag_SA_pt;
  double tag_SA_eta;
  double tag_SA_phi;
  double tag_CB_pt;
  double tag_CB_eta;
  double tag_CB_phi;
  double probe_pt;
  double probe_eta;
  double probe_phi;
  double probe_charge;
  double tp_dR;
  double tp_deta;
  double tp_dphi;
  double tp_extdR;
  double tp_extdeta;
  double tp_extdphi;
  double tp_mass;
  vector < int >* probe_mesL1_pass;
  vector < double >* probe_mesL1_dR;
  vector < double >* probe_mesL1_tpdR;
  vector < double >* probe_mesL1_pt;
  vector < double >* probe_mesL1_eta;
  vector < double >* probe_mesL1_phi;
  vector < int >* probe_mesL1_MoreCandInRoI;
  vector < int >* probe_mesL1_MoreCandInSector;
  vector < int >* probe_mesL1_charge;
  vector < int >* probe_mesSA_pass;
  vector < double >* probe_mesSA_dR;
  vector < double >* probe_mesSA_tpdR;
  vector < double >* probe_mesSA_pt;
  vector < double >* probe_mesSA_eta;
  vector < double >* probe_mesSA_phi;
  vector < double >* probe_mesSA_etams;
  vector < double >* probe_mesSA_phims;
  vector < double >* probe_mesSA_etabe;
  vector < double >* probe_mesSA_phibe;
  vector < int >* probe_mesCB_pass;
  vector < double >* probe_mesCB_dR;
  vector < double >* probe_mesCB_tpdR;
  vector < double >* probe_mesCB_pt;
  vector < double >* probe_mesCB_eta;
  vector < double >* probe_mesCB_phi;

  mes_n             = 0;
  mes_name          = new vector < string > ();
  tag_proc          = -99999.;
  tag_dRL1          = -99999.;
  tag_pt            = -99999.;
  tag_eta           = -99999.;
  tag_exteta        = -99999.;
  tag_extinneta     = -99999.;
  tag_phi           = -99999.;
  tag_extphi        = -99999.;
  tag_extinnphi     = -99999.;
  tag_charge        = -99999.;
  tag_L1_pt         = -99999.;
  tag_L1_eta        = -99999.;
  tag_L1_phi        = -99999.;
  tag_SA_pt         = -99999.;
  tag_SA_eta        = -99999.;
  tag_SA_phi        = -99999.;
  tag_CB_pt         = -99999.;
  tag_CB_eta        = -99999.;
  tag_CB_phi        = -99999.;
  probe_pt          = -99999.;
  probe_eta         = -99999.;
  probe_phi         = -99999.;
  probe_charge      = -99999.;
  tp_dR             = -99999.;
  tp_deta           = -99999.;
  tp_dphi           = -99999.;
  tp_extdR          = -99999.;
  tp_extdeta        = -99999.;
  tp_extdphi        = -99999.;
  tp_mass           = -99999.;
  probe_mesL1_pass  = new vector < int > ();
  probe_mesL1_dR    = new vector < double > ();
  probe_mesL1_tpdR  = new vector < double > ();
  probe_mesL1_pt    = new vector < double > ();
  probe_mesL1_eta   = new vector < double > ();
  probe_mesL1_phi   = new vector < double > ();
  probe_mesL1_MoreCandInRoI    = new vector < int > ();
  probe_mesL1_MoreCandInSector = new vector < int > ();
  probe_mesL1_charge           = new vector < int > ();
  probe_mesSA_pass  = new vector < int > ();
  probe_mesSA_dR    = new vector < double > ();
  probe_mesSA_tpdR  = new vector < double > ();
  probe_mesSA_pt    = new vector < double > ();
  probe_mesSA_eta   = new vector < double > ();
  probe_mesSA_phi   = new vector < double > ();
  probe_mesSA_etams = new vector < double > ();
  probe_mesSA_phims = new vector < double > ();
  probe_mesSA_etabe = new vector < double > ();
  probe_mesSA_phibe = new vector < double > ();
  probe_mesCB_pass  = new vector < int > ();
  probe_mesCB_dR    = new vector < double > ();
  probe_mesCB_tpdR  = new vector < double > ();
  probe_mesCB_pt    = new vector < double > ();
  probe_mesCB_eta   = new vector < double > ();
  probe_mesCB_phi   = new vector < double > ();

  //--------------------------------------------------
  // BRANCH SET UP
  //--------------------------------------------------

  tree->SetBranchAddress( "mes_n",        &mes_n );
  tree->SetBranchAddress( "mes_name",     &mes_name );
  tree->SetBranchAddress( "tag_proc",     &tag_proc );
  tree->SetBranchAddress( "tag_dRL1",     &tag_dRL1 );
  tree->SetBranchAddress( "tag_pt",       &tag_pt );
  tree->SetBranchAddress( "tag_eta",      &tag_eta );
  tree->SetBranchAddress( "tag_phi",      &tag_phi );
  tree->SetBranchAddress( "tag_charge",   &tag_charge );
  tree->SetBranchAddress( "tag_L1_pt",    &tag_L1_pt );
  tree->SetBranchAddress( "tag_L1_eta",   &tag_L1_eta );
  tree->SetBranchAddress( "tag_L1_phi",   &tag_L1_phi );
  tree->SetBranchAddress( "tag_SA_pt",    &tag_SA_pt );
  tree->SetBranchAddress( "tag_SA_eta",   &tag_SA_eta );
  tree->SetBranchAddress( "tag_SA_phi",   &tag_SA_phi );
  tree->SetBranchAddress( "tag_CB_pt",    &tag_CB_pt );
  tree->SetBranchAddress( "tag_CB_eta",   &tag_CB_eta );
  tree->SetBranchAddress( "tag_CB_phi",   &tag_CB_phi );
  tree->SetBranchAddress( "probe_pt",           &probe_pt );
  tree->SetBranchAddress( "probe_eta",          &probe_eta );
  tree->SetBranchAddress( "probe_phi",          &probe_phi );
  tree->SetBranchAddress( "probe_charge",       &probe_charge );
  tree->SetBranchAddress( "tp_dR",              &tp_dR );
  tree->SetBranchAddress( "tp_deta",            &tp_deta );
  tree->SetBranchAddress( "tp_dphi",            &tp_dphi );
  tree->SetBranchAddress( "tp_extdR",           &tp_extdR );
  tree->SetBranchAddress( "tp_extdeta",         &tp_extdeta );
  tree->SetBranchAddress( "tp_extdphi",         &tp_extdphi );
  tree->SetBranchAddress( "tp_mass",            &tp_mass );
  tree->SetBranchAddress( "probe_mesL1_pass",   &probe_mesL1_pass );
  tree->SetBranchAddress( "probe_mesL1_dR",     &probe_mesL1_dR );
  tree->SetBranchAddress( "probe_mesL1_tpdR",   &probe_mesL1_tpdR );
  tree->SetBranchAddress( "probe_mesL1_pt",     &probe_mesL1_pt );
  tree->SetBranchAddress( "probe_mesL1_eta",    &probe_mesL1_eta );
  tree->SetBranchAddress( "probe_mesL1_phi",    &probe_mesL1_phi );
  tree->SetBranchAddress( "probe_mesL1_MoreCandInRoI",    &probe_mesL1_MoreCandInRoI );
  tree->SetBranchAddress( "probe_mesL1_MoreCandInSector", &probe_mesL1_MoreCandInSector );
  tree->SetBranchAddress( "probe_mesL1_charge",           &probe_mesL1_charge );
  tree->SetBranchAddress( "probe_mesSA_pass",   &probe_mesSA_pass );
  tree->SetBranchAddress( "probe_mesSA_dR",     &probe_mesSA_dR );
  tree->SetBranchAddress( "probe_mesSA_tpdR",   &probe_mesSA_tpdR );
  tree->SetBranchAddress( "probe_mesSA_pt",     &probe_mesSA_pt );
  tree->SetBranchAddress( "probe_mesSA_eta",    &probe_mesSA_eta );
  tree->SetBranchAddress( "probe_mesSA_phi",    &probe_mesSA_phi );
  tree->SetBranchAddress( "probe_mesSA_etams",  &probe_mesSA_etams );
  tree->SetBranchAddress( "probe_mesSA_phims",  &probe_mesSA_phims );
  tree->SetBranchAddress( "probe_mesSA_etabe",  &probe_mesSA_etabe );
  tree->SetBranchAddress( "probe_mesSA_phibe",  &probe_mesSA_phibe );
  tree->SetBranchAddress( "probe_mesCB_pass",   &probe_mesCB_pass );
  tree->SetBranchAddress( "probe_mesCB_dR",     &probe_mesCB_dR );
  tree->SetBranchAddress( "probe_mesCB_tpdR",   &probe_mesCB_tpdR );
  tree->SetBranchAddress( "probe_mesCB_pt",     &probe_mesCB_pt );
  tree->SetBranchAddress( "probe_mesCB_eta",    &probe_mesCB_eta );
  tree->SetBranchAddress( "probe_mesCB_phi",    &probe_mesCB_phi );


  Long64_t nentries_d = tree->GetEntriesFast();
  Int_t nbytes = 0, nb = 0;

  cout << "nentries_d: " << nentries_d << endl;

  TH1D* h_mass = new TH1D("h_mass","",100,2600,3600);
  TH1D* h_tag_pt   = new TH1D("h_tag_pt",  "",100,0,500);
  TH1D* h_probe_pt = new TH1D("h_probe_pt","",100,0,500);

  const int nbin_dR = 50;
  const double xmin_dR = 0;
  const double xmax_dR = 1;

  TH1D* h0_br_dR = new TH1D("h0_br_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h1_br_dR = new TH1D("h1_br_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h2_br_dR = new TH1D("h2_br_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h3_br_dR = new TH1D("h3_br_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h4_br_dR = new TH1D("h4_br_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h5_br_dR = new TH1D("h5_br_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h6_br_dR = new TH1D("h6_br_dR","",nbin_dR,xmin_dR,xmax_dR);

  TH1D* h0_ec_dR = new TH1D("h0_ec_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h1_ec_dR = new TH1D("h1_ec_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h2_ec_dR = new TH1D("h2_ec_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h3_ec_dR = new TH1D("h3_ec_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h4_ec_dR = new TH1D("h4_ec_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h5_ec_dR = new TH1D("h5_ec_dR","",nbin_dR,xmin_dR,xmax_dR);
  TH1D* h6_ec_dR = new TH1D("h6_ec_dR","",nbin_dR,xmin_dR,xmax_dR);

  h0_br_dR->SetFillColor(col0_dR);
  h1_br_dR->SetFillColor(col1_dR);
  h2_br_dR->SetFillColor(col2_dR);
  h3_br_dR->SetFillColor(col3_dR);

  h0_ec_dR->SetFillColor(col0_dR);
  h1_ec_dR->SetFillColor(col1_dR);
  h2_ec_dR->SetFillColor(col2_dR);
  h3_ec_dR->SetFillColor(col3_dR);

  int index = -1;
  if(TrigChain=="mu4") index = 0;
  else if(TrigChain=="mu6") index = 1;

  if(index <0) {
    cout << "unknown trigger chain: " << TrigChain << endl;
    return;
  }


  double current_mass = -999;
  double previous_mass = 999;

  int evt_count = 0;

  double ZERO = 1E-10;

  double even_L1_eta = -999;
  double even_L1_phi = -999;
  double even_SA_pt = -999;
  double even_SA_eta = -999;
  double even_SA_phi = -999;
  double odd_L1_eta = -999;
  double odd_L1_phi = -999;
  double odd_SA_pt = -999;
  double odd_SA_eta = -999;
  double odd_SA_phi = -999;

  bool sameSA = false;
  bool sameL1 = false;

  bool even_pass_L1 = false;
  bool even_pass_SA = false;
  bool even_pass_CB = false;
  bool odd_pass_L1 = false;
  bool odd_pass_SA = false;
  bool odd_pass_CB = false;

  for (Long64_t jentry=0; jentry<nentries_d;jentry++) {
    nb = tree->GetEntry(jentry);   nbytes += nb;

    if(mes_name->at(index) != TrigChain) {
      cout << "inconsistent trigger chain " << mes_name->at(index) << " " << TrigChain << endl;
      return;
    }

    h_mass->Fill(tp_mass);

    if(3099. - 300. > tp_mass || tp_mass > 3099. + 300) continue;

    h_tag_pt  ->Fill(tag_pt*0.001);
    h_probe_pt->Fill(probe_pt*0.001);

    if(tag_pt*0.001<8. || probe_pt*0.001<8) continue;


    current_mass = tp_mass;
    if(fabs(current_mass-previous_mass) > ZERO &&
        evt_count%2) {
      cout << "odd event should have same mass as even event: " << current_mass << " " << previous_mass << endl;
      return;
    }

    if(evt_count%2 == 0) {
      even_L1_eta = probe_mesL1_eta->at(index);
      even_L1_phi = probe_mesL1_phi->at(index);
      even_SA_pt  = probe_mesSA_pt->at(index);
      even_SA_eta = probe_mesSA_eta->at(index);
      even_SA_phi = probe_mesSA_phi->at(index);

      even_pass_L1 = (probe_mesL1_pass->at(index) > 0);
      even_pass_SA = (probe_mesSA_pass->at(index) > 0);
      even_pass_CB = (probe_mesCB_pass->at(index) > 0);

      // cout << "even" << evt_count << " " << even_SA_eta << " " << even_SA_phi << endl;
    }

    if(evt_count%2 == 1) {
      odd_L1_eta = probe_mesL1_eta->at(index);
      odd_L1_phi = probe_mesL1_phi->at(index);
      odd_SA_pt  = probe_mesSA_pt->at(index);
      odd_SA_eta = probe_mesSA_eta->at(index);
      odd_SA_phi = probe_mesSA_phi->at(index);

      odd_pass_L1 = (probe_mesL1_pass->at(index) > 0);
      odd_pass_SA = (probe_mesSA_pass->at(index) > 0);
      odd_pass_CB = (probe_mesCB_pass->at(index) > 0);

      // cout << "odd " << evt_count << " " << odd_SA_eta << " " << odd_SA_phi << endl;
    }

    if(evt_count%2 == 1) {

      sameL1 = false;
      if(fabs(even_L1_eta - odd_L1_eta) < ZERO &&
          fabs(even_L1_phi - odd_L1_phi) < ZERO)
        sameL1 = true;

      sameSA = false;
      if(fabs(even_SA_pt  - odd_SA_pt) < ZERO &&
          fabs(even_SA_eta - odd_SA_eta) < ZERO &&
          fabs(even_SA_phi - odd_SA_phi) < ZERO)
        sameSA = true;

      if(fabs(even_L1_eta)<1.05) {

        h0_br_dR->Fill(tp_extdR);
        if(even_pass_L1) h1_br_dR->Fill(tp_extdR);
        if(even_pass_L1 && !sameL1) h5_br_dR->Fill(tp_extdR);
        if(even_pass_L1 && even_pass_SA) h2_br_dR->Fill(tp_extdR);
        if(even_pass_L1 && even_pass_SA && !sameSA) h4_br_dR->Fill(tp_extdR);
        if(even_pass_L1 && !sameL1 && even_pass_SA && !sameSA) h6_br_dR->Fill(tp_extdR);
        if(even_pass_L1 && even_pass_SA && even_pass_CB) h3_br_dR->Fill(tp_extdR);

      }
      else {

        h0_ec_dR->Fill(tp_extdR);
        if(even_pass_L1) h1_ec_dR->Fill(tp_extdR);
        if(even_pass_L1 && !sameL1) h5_ec_dR->Fill(tp_extdR);
        if(even_pass_L1 && even_pass_SA) h2_ec_dR->Fill(tp_extdR);
        if(even_pass_L1 && even_pass_SA && !sameSA) h4_ec_dR->Fill(tp_extdR);
        if(even_pass_L1 && !sameL1 && even_pass_SA && !sameSA) h6_ec_dR->Fill(tp_extdR);
        if(even_pass_L1 && even_pass_SA && even_pass_CB) h3_ec_dR->Fill(tp_extdR);

      }

      if(fabs(odd_L1_eta)<1.05) {

        h0_br_dR->Fill(tp_extdR);
        if(odd_pass_L1) h1_br_dR->Fill(tp_extdR);
        if(odd_pass_L1 && !sameL1) h5_br_dR->Fill(tp_extdR);
        if(odd_pass_L1 && odd_pass_SA) h2_br_dR->Fill(tp_extdR);
        if(odd_pass_L1 && odd_pass_SA && !sameSA) h4_br_dR->Fill(tp_extdR);
        if(odd_pass_L1 && !sameL1 && odd_pass_SA && !sameSA) h6_br_dR->Fill(tp_extdR);
        if(odd_pass_L1 && odd_pass_SA && odd_pass_CB) h3_br_dR->Fill(tp_extdR);

      }
      else {

        h0_ec_dR->Fill(tp_extdR);
        if(odd_pass_L1) h1_ec_dR->Fill(tp_extdR);
        if(odd_pass_L1 && !sameL1) h5_ec_dR->Fill(tp_extdR);
        if(odd_pass_L1 && odd_pass_SA) h2_ec_dR->Fill(tp_extdR);
        if(odd_pass_L1 && odd_pass_SA && !sameSA) h4_ec_dR->Fill(tp_extdR);
        if(odd_pass_L1 && !sameL1 && odd_pass_SA && !sameSA) h6_ec_dR->Fill(tp_extdR);
        if(odd_pass_L1 && odd_pass_SA && odd_pass_CB) h3_ec_dR->Fill(tp_extdR);

      }

    }

    previous_mass = current_mass;
    evt_count++;
  }


  TEfficiency* eff01_br_dR = new TEfficiency(*h1_br_dR,*h0_br_dR);
  TEfficiency* eff12_br_dR = new TEfficiency(*h2_br_dR,*h1_br_dR);
  TEfficiency* eff23_br_dR = new TEfficiency(*h3_br_dR,*h2_br_dR);
  TEfficiency* eff14_br_dR = new TEfficiency(*h4_br_dR,*h1_br_dR);
  TEfficiency* eff05_br_dR = new TEfficiency(*h5_br_dR,*h0_br_dR);
  TEfficiency* eff56_br_dR = new TEfficiency(*h6_br_dR,*h5_br_dR);

  TEfficiency* eff01_ec_dR = new TEfficiency(*h1_ec_dR,*h0_ec_dR);
  TEfficiency* eff12_ec_dR = new TEfficiency(*h2_ec_dR,*h1_ec_dR);
  TEfficiency* eff23_ec_dR = new TEfficiency(*h3_ec_dR,*h2_ec_dR);
  TEfficiency* eff14_ec_dR = new TEfficiency(*h4_ec_dR,*h1_ec_dR);
  TEfficiency* eff05_ec_dR = new TEfficiency(*h5_ec_dR,*h0_ec_dR);
  TEfficiency* eff56_ec_dR = new TEfficiency(*h6_ec_dR,*h5_ec_dR);

  eff01_br_dR->SetLineColor(col01_dR);
  eff12_br_dR->SetLineColor(col12_dR);
  eff23_br_dR->SetLineColor(col23_dR);
  eff14_br_dR->SetLineColor(col14_dR);
  eff05_br_dR->SetLineColor(col05_dR);
  eff56_br_dR->SetLineColor(col56_dR);

  eff01_ec_dR->SetLineColor(col01_dR);
  eff12_ec_dR->SetLineColor(col12_dR);
  eff23_ec_dR->SetLineColor(col23_dR);
  eff14_ec_dR->SetLineColor(col14_dR);
  eff05_ec_dR->SetLineColor(col05_dR);
  eff56_ec_dR->SetLineColor(col56_dR);

  eff01_br_dR->SetMarkerColor(col01_dR);
  eff12_br_dR->SetMarkerColor(col12_dR);
  eff23_br_dR->SetMarkerColor(col23_dR);
  eff14_br_dR->SetMarkerColor(col14_dR);
  eff05_br_dR->SetMarkerColor(col05_dR);
  eff56_br_dR->SetMarkerColor(col56_dR);

  eff01_ec_dR->SetMarkerColor(col01_dR);
  eff12_ec_dR->SetMarkerColor(col12_dR);
  eff23_ec_dR->SetMarkerColor(col23_dR);
  eff14_ec_dR->SetMarkerColor(col14_dR);
  eff05_ec_dR->SetMarkerColor(col05_dR);
  eff56_ec_dR->SetMarkerColor(col56_dR);

  eff05_br_dR->SetMarkerSize(1.1);
  eff05_ec_dR->SetMarkerSize(1.1);

  TCanvas* c1 = new TCanvas("c1");
  h_mass->Draw();
  c1 -> Print( pdf + "[", "pdf" );
  c1->Print(pdf , "pdf");

  TCanvas* c2 = new TCanvas("c2");
  h_probe_pt->SetFillColor(col0_dR);
  h_probe_pt->Draw();
  h_tag_pt->Draw("same");
  c2->Print(pdf , "pdf");



  TCanvas* c1_br_dR = new TCanvas("c1_br_dR");
  h0_br_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  h0_br_dR->GetYaxis()->SetTitle("");
  h0_br_dR->Draw("hist");
  h1_br_dR->Draw("histsame");
  h2_br_dR->Draw("histsame");
  h3_br_dR->Draw("histsame");
  myText(0.65,0.86,1, "J/#psi MC");
  myText(0.65,0.80,1, "MU4");
  // myText(0.65,0.80,1, "\"JpsitapMC\"");
  myText(0.65,0.74,1, "\"NoTag\"");
  myText(0.65,0.68,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.62,1, "probe |#it{#eta}^{L1}| < 1.05");

  myText(0.23,0.86,col0_dR, "Probe");
  myText(0.23,0.80,col1_dR, "L1");
  myText(0.23,0.74,col2_dR, "SA");
  myText(0.23,0.68,col3_dR, "CB");

  if(epsdir!=""){
    //c1_br_dR->SaveAs(epsdir+"/dR_barrel.eps");
    c1_br_dR->Print(pdf , "pdf");
  }

  TCanvas* c2_br_dR = new TCanvas("c2_br_dR");
  TH1F* frame_br_dR = gPad->DrawFrame(xmin_dR,0,xmax_dR,1);
  frame_br_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  frame_br_dR->GetYaxis()->SetTitle("efficiency");
  eff01_br_dR->Draw("psame");
  eff12_br_dR->Draw("psame");
  eff23_br_dR->Draw("psame");
  myText(0.65,0.49,1, "J/#psi MC");
  myText(0.65,0.43,1, "MU4");
  // myText(0.65,0.37,1, "\"JpsitapMC\"");
  myText(0.65,0.37,1, "\"NoTag\"");
  myText(0.65,0.31,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.25,1, "probe |#it{#eta}^{L1}| < 1.05");

  myText(0.23,0.37,col01_dR, "L1");
  myText(0.23,0.31,col12_dR, "SA/L1");
  myText(0.23,0.25,col23_dR, "CB/SA");

  if(epsdir!=""){
    //c2_br_dR->SaveAs(epsdir+"/dR_barrel_ratio.eps");
    c2_br_dR->Print(pdf , "pdf");
  }

  TCanvas* c3_br_dR = new TCanvas("c3_br_dR");
  TH1F* frame2_br_dR = gPad->DrawFrame(xmin_dR,0,xmax_dR,1);
  frame2_br_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  frame2_br_dR->GetYaxis()->SetTitle("efficiency");
  eff12_br_dR->Draw("psame");
  eff14_br_dR->Draw("psame");
  // eff56_br_dR->Draw("psame");
  myText(0.65,0.55,1, "J/#psi MC");
  myText(0.65,0.49,1, "MU4");
  // myText(0.65,0.37,1, "\"JpsitapMC\"");
  myText(0.65,0.43,1, "\"NoTag\"");
  myText(0.65,0.37,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.31,1, "probe |#it{#eta}^{L1}| < 1.05");

  myText(0.23,0.37,col12_dR, "SA/L1");
  myText(0.23,0.31,col14_dR, "(SA && separated)/L1");
  // myText(0.23,0.25,col56_dR, "(SA && SA_separated)/(L1 && L1_separated)");

  if(epsdir!=""){
    //c3_br_dR->SaveAs(epsdir+"/dR_barrel_ratio2.eps");
    c3_br_dR->Print(pdf , "pdf");
  }


  TCanvas* c4_br_dR = new TCanvas("c4_br_dR");
  TH1F* frame3_br_dR = gPad->DrawFrame(xmin_dR,0,xmax_dR,1);
  frame3_br_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  frame3_br_dR->GetYaxis()->SetTitle("efficiency");
  eff01_br_dR->Draw("psame");
  eff05_br_dR->Draw("psame");
  myText(0.65,0.49,1, "J/#psi MC");
  myText(0.65,0.43,1, "MU4");
  // myText(0.65,0.37,1, "\"JpsitapMC\"");
  myText(0.65,0.37,1, "\"NoTag\"");
  myText(0.65,0.31,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.25,1, "probe |#it{#eta}^{L1}| < 1.05");

  myText(0.23,0.31,col01_dR, "L1");
  myText(0.23,0.25,col05_dR, "L1 && L1_separated");

  if(epsdir!=""){
    //c4_br_dR->SaveAs(epsdir+"/dR_barrel_ratio3.eps");
    c4_br_dR->Print(pdf , "pdf");
  }



  TCanvas* c1_ec_dR = new TCanvas("c1_ec_dR");
  h0_ec_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  h0_ec_dR->GetYaxis()->SetTitle("");
  h0_ec_dR->Draw("hist");
  h1_ec_dR->Draw("histsame");
  h2_ec_dR->Draw("histsame");
  h3_ec_dR->Draw("histsame");
  myText(0.65,0.86,1, "J/#psi MC");
  myText(0.65,0.80,1, "MU4");
  // myText(0.65,0.80,1, "\"JpsitapMC\"");
  myText(0.65,0.74,1, "\"NoTag\"");
  myText(0.65,0.68,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.62,1, "probe |#it{#eta}^{L1}| > 1.05");

  myText(0.23,0.86,col0_dR, "Probe");
  myText(0.23,0.80,col1_dR, "L1");
  myText(0.23,0.74,col2_dR, "SA");
  myText(0.23,0.68,col3_dR, "CB");

  if(epsdir!=""){
    c1_ec_dR->Print(pdf , "pdf");
    //c1_ec_dR->SaveAs(epsdir+"/dR_endcap.eps");
  }

  TCanvas* c2_ec_dR = new TCanvas("c2_ec_dR");
  TH1F* frame_ec_dR = gPad->DrawFrame(xmin_dR,0,xmax_dR,1);
  frame_ec_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  frame_ec_dR->GetYaxis()->SetTitle("efficiency");
  eff01_ec_dR->Draw("psame");
  eff12_ec_dR->Draw("psame");
  eff23_ec_dR->Draw("psame");
  myText(0.65,0.49,1, "J/#psi MC");
  myText(0.65,0.43,1, "MU4");
  // myText(0.65,0.37,1, "\"JpsitapMC\"");
  myText(0.65,0.37,1, "\"NoTag\"");
  myText(0.65,0.31,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.25,1, "probe |#it{#eta}^{L1}| > 1.05");

  myText(0.23,0.37,col01_dR, "L1");
  myText(0.23,0.31,col12_dR, "SA/L1");
  myText(0.23,0.25,col23_dR, "CB/SA");

  if(epsdir!=""){
    //c2_ec_dR->SaveAs(epsdir+"/dR_endcap_ratio.eps");
    c2_ec_dR->Print(pdf , "pdf");
  }

  TCanvas* c3_ec_dR = new TCanvas("c3_ec_dR");
  TH1F* frame2_ec_dR = gPad->DrawFrame(xmin_dR,0,xmax_dR,1);
  frame2_ec_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  frame2_ec_dR->GetYaxis()->SetTitle("efficiency");
  eff12_ec_dR->Draw("psame");
  eff14_ec_dR->Draw("psame");
  // eff56_ec_dR->Draw("psame");
  myText(0.65,0.55,1, "J/#psi MC");
  myText(0.65,0.49,1, "MU4");
  // myText(0.65,0.37,1, "\"JpsitapMC\"");
  myText(0.65,0.43,1, "\"NoTag\"");
  myText(0.65,0.37,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.31,1, "probe |#it{#eta}^{L1}| > 1.05");

  myText(0.23,0.37,col12_dR, "SA/L1");
  myText(0.23,0.31,col14_dR, "(SA && separated)/L1");
  // myText(0.23,0.25,col56_dR, "(SA && SA_separated)/(L1 && L1_separated)");

  if(epsdir!=""){
    //c3_ec_dR->SaveAs(epsdir+"/dR_endcap_ratio2.eps");
    c3_ec_dR->Print(pdf , "pdf");
  }

  TCanvas* c4_ec_dR = new TCanvas("c4_ec_dR");
  TH1F* frame3_ec_dR = gPad->DrawFrame(xmin_dR,0,xmax_dR,1);
  frame3_ec_dR->GetXaxis()->SetTitle("#DeltaR_{tag,probe}^{ext}");
  frame3_ec_dR->GetYaxis()->SetTitle("efficiency");
  eff01_ec_dR->Draw("psame");
  eff05_ec_dR->Draw("psame");
  myText(0.65,0.49,1, "J/#psi MC");
  myText(0.65,0.43,1, "MU4");
  // myText(0.65,0.37,1, "\"JpsitapMC\"");
  myText(0.65,0.37,1, "\"NoTag\"");
  myText(0.65,0.31,1, "#it{p}_{T}^{offline} > 8 GeV");
  myText(0.65,0.25,1, "probe |#it{#eta}^{L1}| > 1.05");

  myText(0.23,0.31,col01_dR, "L1");
  myText(0.23,0.25,col05_dR, "L1 && L1_separated");

  if(epsdir!=""){
    //c4_ec_dR->SaveAs(epsdir+"/dR_endcap_ratio3.eps");
    c4_ec_dR->Print(pdf , "pdf");
    c4_ec_dR -> Print( pdf + "]", "pdf" );
  }


  return;
}
