#ifndef SimG4CMS_CaloTrkProcessing_H
#define SimG4CMS_CaloTrkProcessing_H

#include "SimG4Core/Notification/interface/Observer.h"
#include "SimG4Core/SensitiveDetector/interface/SensitiveCaloDetector.h"

#include "CondFormats/GeometryObjects/interface/CaloSimulationParameters.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "G4VTouchable.hh"
#include "G4Track.hh"
#include "DataFormats/Math/interface/LorentzVector.h"

#include <map>
#include <vector>
#include <string>
#include <iostream>

class BeginOfEvent;
class G4LogicalVolume;
class G4Step;
class SimTrackManager;

class CaloTrkProcessing : public SensitiveCaloDetector,
                          public Observer<const BeginOfEvent*>,
                          public Observer<const G4Step*> {
public:
  CaloTrkProcessing(const std::string& aSDname,
                    const CaloSimulationParameters& csps,
                    const SensitiveDetectorCatalog& clg,
                    bool testBeam,
                    double eMin,
                    bool putHistory,
                    bool doFineCalo,
                    double eMinFine,
                    int addlevel,
                    const std::vector<std::string>& fineNames,
                    const std::vector<int>& fineLevels,
                    const std::vector<int>& useFines,
                    const SimTrackManager*);
  ~CaloTrkProcessing() override;
  void Initialize(G4HCofThisEvent*) override {}
  void clearHits() override {}
  bool ProcessHits(G4Step*, G4TouchableHistory*) override { return true; }
  uint32_t setDetUnitId(const G4Step* step) override { return 0; }
  void EndOfEvent(G4HCofThisEvent*) override {}
  void fillHits(edm::PCaloHitContainer&, const std::string&) override {}

private:
  struct Detector {
    Detector() {}
    std::string name;
    G4LogicalVolume* lv;
    int level;
    std::vector<std::string> fromDets;
    std::vector<G4LogicalVolume*> fromDetL;
    std::vector<int> fromLevels;
  };

  void update(const BeginOfEvent* evt) override;
  void update(const G4Step*) override;
  int isItCalo(const G4VTouchable*, const std::vector<Detector>&);
  int isItInside(const G4VTouchable*, int, int);

  // Utilities to get detector levels during a step
  int detLevels(const G4VTouchable*) const;
  G4LogicalVolume* detLV(const G4VTouchable*, int) const;
  void detectorLevel(const G4VTouchable*, int&, int*, G4String*) const;

  const bool testBeam_;
  const double eMin_;
  const bool putHistory_;
  bool doFineCalo_;
  const double eMinFine_;
  const int addlevel_;
  int lastTrackID_;
  std::vector<Detector> detectors_, fineDetectors_;
};

#endif
