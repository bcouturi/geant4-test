#include "PWorld.hh"
#include "SensitiveDetector.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"

namespace B1
{
    PWorld::PWorld(G4String worldName)
        : G4VUserParallelWorld(worldName)
    {        }

    PWorld::~PWorld()
    {
        delete fGhostLogical;
        delete fSurfaceSD;
    }

    void PWorld::Construct()
    {
        G4VPhysicalVolume *ghostWorld = GetWorld();
        G4LogicalVolume *worldLogical = ghostWorld->GetLogicalVolume();

        // place volumes in the parallel world here. For example ...
        //
        G4Box *ghostSolid = new G4Box("GhostdBox", 400. * cm, 400. * cm, 1. * cm);
        fGhostLogical = new G4LogicalVolume(ghostSolid, 0, "GhostLogical", 0, 0, 0);
        new G4PVPlacement(0, G4ThreeVector(0, 0, 4 * cm), fGhostLogical,
                          "GhostPhysical", worldLogical, 0, 0);



        G4SDManager* sdManager = G4SDManager::GetSDMpointer();
        fSurfaceSD = new SensitiveDetector("SurfaceSD");
        sdManager->AddNewDetector(fSurfaceSD);
        fGhostLogical->SetSensitiveDetector(fSurfaceSD);
    }

}