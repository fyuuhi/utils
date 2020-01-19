
# common JO for almost all slices
#
#  flags for command-line input
from RecExConfig.RecFlags import rec
from AthenaCommon.AthenaCommonFlags import athenaCommonFlags as acf
acf.FilesInput=[
    "/afs/cern.ch/user/b/baines/work/public/data/ftk_rawdata_v2/ttbar/user.jahreda.mc15_13TeV.410000.recon.RDO.e3698_s2608_s2183_r6630_20.7.2.3.updatesJohn.newFormat.v1_EXT2.58456700/user.jahreda.7261042.EXT2._000001.RDO_FTK.pool.root"
    #"/afs/cern.ch/user/b/baines/work/public/data/user.jahreda.mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.RDO_FTK.e3698_s2608_s2183_r6630.test.v2_EXT2.39080319/user.jahreda.6259805.EXT2._000005.RDO_FTK.pool.root"
    ]

if not acf.EvtMax.is_locked():
    acf.EvtMax=5
if not ('OutputLevel' in dir()):
    rec.OutputLevel=INFO

if ('enableCostMonitoring' in dir() and bool(enableCostMonitoring) == True):
    enableCostMonitoring = True
else: 
    enableCostMonitoring = False

#RTT runs with costMonitoring on - test whether it is available in a given release
#test whether a package is useable in this release
import imp
try:
    imp.find_module('TrigCostD3PDMaker')
except:
    print 'CostMonitoring packages not available, setting  enableCostMonitoring=False'
    enableCostMonitoring=False

# flags for RecExCommon
doTrigger=True
TriggerModernConfig=True
rec.doWriteAOD=True
rec.doWriteESD=True
rec.doWriteTAG=False
rec.doAOD=True 
rec.doESD.set_Value_and_Lock(False) 
doTAG=False
#rec.doTruth=True
rec.doTruth.set_Value_and_Lock(False)

#-----------------------------------------------------------
include("RecExCond/RecExCommon_flags.py")
#-----------------------------------------------------------

TriggerFlags.doFTK=True

# set up trigger monitoring                                                                                                                                                        
if not ('RunningRTT' in dir() and bool(RunningRTT) == True):
    TriggerFlags.enableMonitoring = [ 'Validation', 'Time' , 'Log' ]
else:
    TriggerFlags.enableMonitoring = [ 'Validation', 'Time'  ]

#menu="MC_pp_v6"
menu="MC_pp_v6_no_prescale"

# set trigger menu
TriggerFlags.readHLTconfigFromXML=False
TriggerFlags.readLVL1configFromXML=False
if  ('menu' in dir()):
    TriggerFlags.triggerMenuSetup=menu 
else: 
    print 'No MENU was set - this is required when using this JO! -  WARNING  falling back to TriggerFlags standard menu'

TriggerFlags.doHLT=True
#TriggerFlags.doL1Topo=True 

def egammaOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.EgammaSlice.setAll()

def muonOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.MuonSlice.setAll()

def jetOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.JetSlice.setAll()

def bjetOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.BjetSlice.setAll()

def bphysicsOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.BphysicsSlice.setAll()

def metOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.METSlice.setAll()

def tauOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.TauSlice.setAll() 

def minbiasOnly():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.MinBiasSlice.setAll() 

def minbiasEnhanced():
    TriggerFlags.Slices_all_setOff()
    TriggerFlags.MinBiasSlice.setAll()
    mbL1Items = ['L1_BCM_Wide', 'L1_LUCID', 'L1_MBTS_2', 'L1_MBTS_1_1', 'L1_TE20', 'L1_TE30', 'L1_TE40', 'L1_RD0_FILLED', 'L1_MBTS_2_UNPAIRED_ISO', 'L1_MBTS_4_4',]
    for L1item in mbL1Items:        
        if not L1item in TriggerFlags.Lvl1.items():
            TriggerFlags.Lvl1.items = TriggerFlags.Lvl1.items() + [L1item]
    mbHLTItems = [
                  ['mb_sptrk_L1MBTS_1',  'L1_MBTS_1', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ['mb_sptrk_L1MBTS_2',  'L1_MBTS_2', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ['mb_sptrk_noisesup_L1MBTS_1',  'L1_MBTS_1', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ['mb_sptrk_noisesup_L1MBTS_2',  'L1_MBTS_2', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ['mb_sp2000_trk70_hmt_L1MBTS_1',  'L1_MBTS_1', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],                  
                  ['mb_sp2000_trk70_hmt_L1MBTS_2',  'L1_MBTS_2', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ['mb_sp2000_pusup600_trk70_hmt_L1MBTS_1', 'L1_MBTS_1', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ['mb_sptrk_costr_L1MBTS_1', 'L1_MBTS_1', [], ['MinBias'], ["BW:MinBias", "RATE:MinBias"], -1],
                  ]
    TriggerFlags.MinBiasSlice.signatures = mbHLTItems
    for HLTitem in mbHLTItems:        
        if not HLTitem in TriggerFlags.MinBiasSlice.signatures():
            TriggerFlags.MinBiasSlice.signatures = TriggerFlags.MinBiasSlice.signatures() + [HLTitem]

try:
    from TriggerMenu import useNewTriggerMenu
    useNewTM = useNewTriggerMenu()
    log.info("Using new TriggerMenu: %r" % useNewTM)
except:
    useNewTM = False
    log.info("Using old TriggerMenuPython since TriggerMenu.useNewTriggerMenu can't be imported")

if useNewTM:
    from TriggerMenu.menu.GenerateMenu import GenerateMenu
else:
    from TriggerMenuPython.GenerateMenu import GenerateMenu


# flags for command-line input
if  ('sliceName' in dir()):
    if  sliceName == 'egamma':
        GenerateMenu.overwriteSignaturesWith(egammaOnly)
    elif sliceName == 'muon':
        GenerateMenu.overwriteSignaturesWith(muonOnly)
    elif sliceName == 'jet':
        GenerateMenu.overwriteSignaturesWith(jetOnly)    
    elif sliceName == 'bjet':
        GenerateMenu.overwriteSignaturesWith(bjetOnly)
    elif sliceName == 'bphysics':
        GenerateMenu.overwriteSignaturesWith(bphysicsOnly)    
    elif sliceName == 'met':
        GenerateMenu.overwriteSignaturesWith(metOnly)
    elif sliceName == 'tau':
        GenerateMenu.overwriteSignaturesWith(tauOnly)
    elif sliceName == 'minbias':
        GenerateMenu.overwriteSignaturesWith(minbiasOnly)
    elif sliceName == 'minbiasEnhanced':
        GenerateMenu.overwriteSignaturesWith(minbiasEnhanced)
    else:
        log.info("WARNING no sliceName given! pleace check this testconfiguration")

# pre set up trigger monitoring
if 'enableCostMonitoring' in dir() and bool(enableCostMonitoring) == True:
    import TriggerRelease.Modifiers
    getattr(TriggerRelease.Modifiers,'enableCostMonitoring')().preSetup()
    getattr(TriggerRelease.Modifiers,'enableCostForCAF')().preSetup()

#-----------------------------------------------------------
include("RecExCommon/RecExCommon_topOptions.py")
#-----------------------------------------------------------
# post set up trigger monitoring
if 'enableCostMonitoring' in dir() and bool(enableCostMonitoring) == True:
    import TriggerRelease.Modifiers
    getattr(TriggerRelease.Modifiers,'enableCostMonitoring')().postSetup()
    getattr(TriggerRelease.Modifiers,'enableCostForCAF')().postSetup()
    getattr(TriggerRelease.Modifiers,'enableCostD3PD')().postSetup()
    # Check if we are debugging the cost mon output - false by default
    if 'enableCostDebug' in dir() and bool(enableCostDebug) == True:
        getattr(TriggerRelease.Modifiers,'enableCostDebug')().postSetup()
#
#-----------------------------------------------------------
#include("TriggerTest/TriggerTestCommon.py")
#-----------------------------------------------------------

#L1 DEBUG for Minbias jobs 
if 'sliceName' in dir() and 'minbias' in sliceName and hasattr(topSequence, "LVL1::TrigT1MBTS"):
    alg = getattr(topSequence, "LVL1::TrigT1MBTS")
    alg.OutputLevel = DEBUG

#from TrigSteerMonitor.TrigSteerMonitorConf import TrigChainMoni
#chainMoni = TrigChainMoni()
#chainMoni.OutputLevel=VERBOSE
#topSequence.TrigSteer_HLT.MonTools += [chainMoni]
#
#import AthenaCommon.Configurable as Configurable
#Configurable.log.setLevel( INFO )
#print topSequence.getChildren()
MessageSvc.verboseLimit = 9999999
MessageSvc.debugLimit = 9999999
MessageSvc.warningLimit = 9999999
MessageSvc.infoLimit = 9999999
MessageSvc.errorLimit = 9999999
