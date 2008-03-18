/*
* PROPRIETARY INFORMATION.  This software is proprietary to
* Side Effects Software Inc., and is not to be reproduced,
* transmitted, or disclosed in any way without written permission.
*
* Produced by:
*	Oleg Samus
*	Side Effects
*	123 Front St. West, Suite 1401
*	Toronto, Ontario
*	Canada   M5J 2M2
*	416-504-9876
*
* NAME:	ROP_FBXActionManager.h (FBX Library, C++)
*
* COMMENTS:	
*
*/
#ifndef __ROP_FBXActionManager_h__
#define __ROP_FBXActionManager_h__

#include <fbx/fbxsdk.h>
#include "ROP_FBXCommon.h"

class ROP_FBXBaseAction;
class ROP_FBXErrorManager;
class ROP_FBXNodeManager;

class ROP_FBXLookAtAction;
class ROP_FBXApplyVertexCacheAction;
class ROP_FBXApplySkinningAction;
class ROP_FBXApplyBlendAction;

class OP_Node;
class ROP_FBXIntTranslator;
/********************************************************************************************************/
typedef vector <ROP_FBXBaseAction *> TActionsVector;
/********************************************************************************************************/
class ROP_FBXActionManager
{
public:
    ROP_FBXActionManager(ROP_FBXNodeManager& node_manager, ROP_FBXErrorManager& error_manager);
    virtual ~ROP_FBXActionManager();

    ROP_FBXLookAtAction* addLookAtAction(KFbxNode* acted_on_node, OP_Node* look_at_node);

    void performPostActions(void);

    /// Clears actions, deleting their objects.
    void clear(void);

    ROP_FBXErrorManager& getErrorManager(void);
    ROP_FBXNodeManager& getNodeManager(void);
    ROP_FBXBaseAction* getCurrentAction(void);

private:
    TActionsVector myPostActions;
    ROP_FBXNodeManager& myNodeManager;
    ROP_FBXErrorManager& myErrorManager;

    ROP_FBXBaseAction* myCurrentAction;

};

/********************************************************************************************************/

#endif // __ROP_FBXActionManager_h__
