
void  roi(){
  const Int_t n = 200;
  const Double_t halfDeltaEta = 0.05;

  Double_t eta[n]   = {0};
  Double_t theta[n] = {0};
  Double_t sinTheta[n] = {0};

  Double_t etaMax[n]          = {0};
  Double_t etaMin[n]          = {0};
  Double_t thetaMax[n]        = {0};
  Double_t thetaMin[n]        = {0};
  Double_t awMax[n]           = {0};
  Double_t awMin[n]           = {0};
  Double_t zMax5000[n]        = {0};
  Double_t zMin5000[n]        = {0};
  Double_t zMax8000[n]        = {0};
  Double_t zMin8000[n]        = {0};
  Double_t zMax10000[n]       = {0};
  Double_t zMin10000[n]       = {0};

  Double_t halfDeltaZ5000[n]  = {0};
  Double_t halfDeltaZ8000[n]  = {0};
  Double_t halfDeltaZ10000[n] = {0};

  for (int i=0;i<n;i++) {
    //eta[i] = 2.5*i/n;
    eta[i] = -2.5 + 2.5*2*i/n;
    theta[i] = atan(exp(-eta[i]))*2;
    sinTheta[i] = sin(theta[i]);
    cout << "i: " << i << endl;
    cout << "eta: " << eta[i] << endl;
    cout << "theta: " << theta[i] << endl;
    cout << "sin: " << sinTheta[i] << endl;

    etaMax[i] = eta[i] + halfDeltaEta;
    etaMin[i] = eta[i] - halfDeltaEta;

    thetaMax[i] = atan(exp(-etaMax[i]))*2;
    thetaMin[i] = atan(exp(-etaMin[i]))*2;

    awMax[i] = tan(thetaMax[i]);
    awMin[i] = tan(thetaMin[i]);

    zMax5000[i] = 5000./(tan(thetaMax[i]));
    zMin5000[i] = 5000./(tan(thetaMin[i]));
    halfDeltaZ5000[i] = sinTheta[i]*fabs(zMax5000[i] - zMin5000[i])/2.;

    zMax8000[i] = 8000./(tan(thetaMax[i]));
    zMin8000[i] = 8000./(tan(thetaMin[i]));
    halfDeltaZ8000[i] = sinTheta[i]*fabs(zMax8000[i] - zMin8000[i])/2.;

    zMax10000[i] = 10000./(tan(thetaMax[i]));
    zMin10000[i] = 10000./(tan(thetaMin[i]));
    halfDeltaZ10000[i] = sinTheta[i]*fabs(zMax10000[i] - zMin10000[i])/2.;

  }

  TGraph *gr5000  = new TGraph(n,eta,halfDeltaZ5000);
  TGraph *gr8000  = new TGraph(n,eta,halfDeltaZ8000);
  TGraph *gr10000 = new TGraph(n,eta,halfDeltaZ10000);

  gr5000->Draw("AP");
  gr5000->SetMarkerColor(1);
  gr5000->GetYaxis()->SetRangeUser(0,2000);
  gr5000->GetXaxis()->SetRangeUser(-2.5,2.5);
  gr5000->SetTitle(";#eta; #DeltaZ/2 [mm]");
  gr8000->Draw("P same");
  gr8000->SetMarkerColor(2);
  gr10000->Draw("P same");
  gr10000->SetMarkerColor(4);


  gPad->SetGrid();
  gStyle->SetLegendBorderSize(0);

  TLegend *leg = new TLegend(0.65,0.2,0.95,0.4);
  leg->AddEntry(gr5000,"R = 5 [m]","p");
  leg->AddEntry(gr8000,"R = 8 [m]","p");
  leg->AddEntry(gr10000,"R = 10 [m]","p");
  leg->SetFillStyle(0);
  leg->Draw("same");
}
