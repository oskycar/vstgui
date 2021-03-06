// This file is part of VSTGUI. It is subject to the license terms
// in the LICENSE file found in the top-level directory of this
// distribution and at http://github.com/steinbergmedia/vstgui/LICENSE

#ifndef __uiviewcreatorcontroller__
#define __uiviewcreatorcontroller__

#include "../uidescription.h"

#if VSTGUI_LIVE_EDITING

#include "../delegationcontroller.h"
#include <vector>
#include <string>

namespace VSTGUI {
class UIViewCreatorDataSource;

//----------------------------------------------------------------------------------------------------
class UIViewCreatorController : public NonAtomicReferenceCounted, public DelegationController, public IContextMenuController
{
public:
	UIViewCreatorController (IController* baseController, UIDescription* description);
	~UIViewCreatorController () override;
	
	IController* getBaseController () const { return controller; }
protected:
	void valueChanged (CControl* pControl) override;
	CView* createView (const UIAttributes& attributes, const IUIDescription* description) override;
	CView* verifyView (CView* view, const UIAttributes& attributes, const IUIDescription* description) override;
	IControlListener* getControlListener (UTF8StringPtr name) override;
	void appendContextMenuItems (COptionMenu& contextMenu, const CPoint& where) override;

	void setupDataSource (UTF8StringPtr filter = nullptr);
	
	UIViewCreatorDataSource* dataSource {nullptr};
	CDataBrowser* dataBrowser {nullptr};
	SharedPointer<UIDescription> description;
	std::vector<std::string> filteredViewNames;
	std::vector<std::string> allViewNames;
	
	enum {
		kSearchFieldTag = 100
	};

};

} // namespace

#endif // VSTGUI_LIVE_EDITING

#endif // __uiviewcreatorcontroller__
