// SensitiveDetector.hh
#ifndef SENSITIVE_DETECTOR_HH
#define SENSITIVE_DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"

namespace B1
{
    class SensitiveDetector : public G4VSensitiveDetector
    {
    public:
        SensitiveDetector(const G4String &name);
        ~SensitiveDetector() override;

        G4bool ProcessHits(G4Step *step, G4TouchableHistory *history) override;
        void Initialize(G4HCofThisEvent *hce) override;
    };

} // namespace B1

#endif