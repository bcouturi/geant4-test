// SensitiveDetector.cc
#include "SensitiveDetector.hh"
#include "G4StepStatus.hh"
#include "G4Track.hh"
#include "G4VTouchable.hh"
#include "G4ios.hh"

namespace B1
{

    SensitiveDetector::SensitiveDetector(const G4String &name)
        : G4VSensitiveDetector(name) {

            std::cout << "XXX SensitiveDetector created " << name << G4endl;


        }

    SensitiveDetector::~SensitiveDetector() {}

    G4bool SensitiveDetector::ProcessHits(G4Step *step, G4TouchableHistory * /*history*/)
    {

        std::cout << "XXX SensitiveDetector::ProcessHits called" << std::endl;

        // Check if the step is on the boundary (entering or exiting the volume)
        if (step->GetPreStepPoint()->GetStepStatus() == fGeomBoundary ||
            step->GetPostStepPoint()->GetStepStatus() == fGeomBoundary)
        {

            // Get hit information
            G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();
            G4double edep = step->GetTotalEnergyDeposit();
            G4ThreeVector momentum = step->GetPreStepPoint()->GetMomentum();

            // Print or store the hit information
            std::cout << "XXX Surface hit at: " << pos << ", Energy deposit: " << edep << G4endl;

            // You can also store this hit in a collection for later analysis
        }

        return true;
    }

    void SensitiveDetector::Initialize(G4HCofThisEvent * /*hce*/)
    {
        // Optional: Initialize hits collection for this event

        std::cout << "XXX SensitiveDetector::Initialize called" << std::endl;
    }

}