#ifndef __IGUISTATE_H
#define __IGUISTATE_H

#include "common/CRect.h"

class CDrawArea;
class CGameGraphicsInterface;

class IGUIState
{
public:
	virtual ~IGUIState() = default;

	// return true if draw is needed
	virtual bool RunFrame() = 0;
	virtual void Draw(CDrawArea& aDirtyArea,CDrawArea& aDrawArea,CGameGraphicsInterface* aGGI) = 0;
	
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void EnterSubState() = 0;
	virtual void ExitSubState() = 0;
};

#endif

