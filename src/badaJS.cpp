#include "badaJS.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Locales;
using namespace Osp::System;
using namespace Osp::App;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Uix;
using namespace Osp::Media;
using namespace Osp::Web::Controls;

#define AC_SOFTKEY_EXIT				0x1001


badaJS::badaJS()
	: __pMainForm(null), __pWeb(null)
{
}


badaJS::~badaJS()
{
}


Application*
badaJS::CreateInstance(void)
{
	// You can create the instance through another constructor.
	return new badaJS();
}


bool
badaJS::OnAppInitializing(AppRegistry& appRegistry)
{
	result r = E_SUCCESS;

	r = __CreateWebForm();
	if (IsFailed(r))
	{
		AppLog("CreateMainForm() has failed.\n");
		goto CATCH;
	}

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	// Create Motion
	__pMotion = new Motion();
	__pMotion->Construct(*this);
	__pMotion->SetEnabled(MOTION_TYPE_ALL);

	/*GetAppFrame()->GetFrame()->AddControl(*__pForm);
	GetAppFrame()->GetFrame()->SetCurrentForm(*__pForm);

*/
	return true;

CATCH:
	return false;
}

bool
badaJS::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate or close any resources still alive.
	// Save the application's current states, if applicable.
	// If this method is successful, return true; otherwise, return false.
	delete __pMotion;
	return true;
}

void
badaJS::OnShakeDetected(MotionState motionState)
{
	switch(motionState)
	{
	case MOTION_STARTED:
		__pWeb->EvaluateJavascriptN(L"shakeStart();");
		break;
	case MOTION_ENDED:
		__pWeb->EvaluateJavascriptN(L"shakeStop();");
		break;
	case MOTION_CANCELLED:
		break;
	case MOTION_INPROGRESS:
		break;
	}
}

void
badaJS::OnDoubleTapDetected(void)
{
	__pWeb->EvaluateJavascriptN(L"doubleTap();");
}

void
badaJS::OnSnapDetected(MotionSnapType snapType)
{
	switch(snapType)
	{
	case MOTION_SNAP_X_POSITIVE:
		__pWeb->EvaluateJavascriptN(L"snap('X+');");
		break;
	case MOTION_SNAP_X_NEGATIVE:
		__pWeb->EvaluateJavascriptN(L"snap('X-');");
		break;
	case MOTION_SNAP_Y_POSITIVE:
		__pWeb->EvaluateJavascriptN(L"snap('Y+');");
		break;
	case MOTION_SNAP_Y_NEGATIVE:
		__pWeb->EvaluateJavascriptN(L"snap('Y-');");
		break;
	case MOTION_SNAP_Z_POSITIVE:
		__pWeb->EvaluateJavascriptN(L"snap('Z+');");
		break;
	case MOTION_SNAP_Z_NEGATIVE:
		__pWeb->EvaluateJavascriptN(L"snap('Z-');");
		break;
	}
}

void
badaJS::OnForeground(void)
{
}


void
badaJS::OnBackground(void)
{
}


void
badaJS::OnLowMemory(void)
{
	// TODO:
	// Deallocate as many resources as possible.
}


void
badaJS::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}

result
badaJS::__CreateWebForm(void)
{
	result r = E_SUCCESS;
	Rectangle bound;
	IAppFrame* pAppFrame = GetAppFrame();

	if (NULL == pAppFrame)
	{
		AppLog("GetAppFrame() has failed.\n");
		goto CATCH;
	}

	/*form*/
	__pMainForm = new Form();
	r = __pMainForm->Construct(FORM_STYLE_SOFTKEY_1|FORM_STYLE_INDICATOR);
	TryCatch(r == E_SUCCESS, , "form is not constructed\n ");

	__pMainForm->SetBackgroundColor(Color(85,104,114));
	__pMainForm->SetSoftkeyText (SOFTKEY_1 , L"Exit");
	__pMainForm->SetSoftkeyActionId (SOFTKEY_1, AC_SOFTKEY_EXIT);
	__pMainForm->AddSoftkeyActionListener (SOFTKEY_1, *this);

	pAppFrame->GetFrame()->AddControl(*__pMainForm);


	/*Web*/
	__pWeb = new Web();
	r = __pWeb->Construct(Rectangle(0, 0, 480, 760));
	TryCatch(r == E_SUCCESS, ,"Web is not constructed\n ");

	r = __pMainForm->AddControl(*__pWeb);
	TryCatch(r == E_SUCCESS, ,"Web is not attached\n ");

	__pWeb->SetFocus();
	__pWeb->LoadUrl(L"/Res/index.html");



	//__pWeb->EvaluateJavascriptN(L"alert('aaa');");
	return r;

CATCH:
	AppLog("Error = %s\n", GetErrorMessage(r));
	return r;
}

void
badaJS::OnActionPerformed(const Control& source, int actionId)
{
	result r = E_SUCCESS;

	switch(actionId)
	{
		case AC_SOFTKEY_EXIT :
			r = Terminate();
			break;
		default:
			break;
	}

	return;

}

void
badaJS::OnTextValueChangeCanceled  ( const Osp::Ui::Control &  source   )
{
}

void
badaJS::OnTextValueChanged  ( const Osp::Ui::Control &  source   )
{
}

void
badaJS::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
badaJS::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
