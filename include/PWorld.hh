#ifndef PWorld_h
#define PWorld_h 1

#include "globals.hh"
#include "G4VUserParallelWorld.hh"
#include "SensitiveDetector.hh"

namespace B1
{
    class PWorld : public G4VUserParallelWorld
    {
    public:
        PWorld(G4String worldName);
        virtual ~PWorld();

        virtual void Construct();

    protected:
        G4LogicalVolume *fGhostLogical;
        SensitiveDetector* fSurfaceSD;
    };
}
#endif
