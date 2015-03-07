﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Partial Classes

This file is generated by: Vczh GacUI Resource Code Generator
************************************************************************
DO NOT MODIFY
***********************************************************************/

#ifndef VCZH_GACUI_RESOURCE_CODE_GENERATOR_Demo_PARTIAL_CLASSES
#define VCZH_GACUI_RESOURCE_CODE_GENERATOR_Demo_PARTIAL_CLASSES

#include "..\..\..\Public\Source\GacUIReflection.h"

namespace demos
{
	class IControlViewModel;
	class IWindowViewModel;
	class CalculatorControl;
	class MainWindow;

	class IControlViewModel : public virtual vl::reflection::IDescriptable, public vl::reflection::Description<IControlViewModel>
	{
	public:

		virtual vl::vint32_t GetFirst() = 0;
		virtual void SetFirst(vl::vint32_t value) = 0;

		virtual vl::vint32_t GetSecond() = 0;
		virtual void SetSecond(vl::vint32_t value) = 0;

		virtual vl::vint32_t GetSum() = 0;
		vl::Event<void()> SumChanged;

		virtual vl::vint32_t GetProduct() = 0;
		vl::Event<void()> ProductChanged;

		virtual void UpdateProduct() = 0;
	};

	class IWindowViewModel : public virtual vl::reflection::IDescriptable, public vl::reflection::Description<IWindowViewModel>
	{
	public:

		virtual vl::Ptr<demos::IControlViewModel> GetControlViewModel() = 0;
	};

	template<typename TImpl>
	class CalculatorControl_ : public vl::presentation::controls::GuiCustomControl, public vl::presentation::GuiInstancePartialClass<vl::presentation::controls::GuiCustomControl>, public vl::reflection::Description<TImpl>
	{
		friend struct vl::reflection::description::CustomTypeDescriptorSelector<TImpl>;
	private:
		Ptr<demos::IControlViewModel> ViewModel_;
	protected:
		vl::presentation::controls::GuiSinglelineTextBox* textBox1;
		vl::presentation::controls::GuiSinglelineTextBox* textBox2;
		vl::presentation::controls::GuiSinglelineTextBox* textBox3;
		vl::presentation::controls::GuiSinglelineTextBox* textBox4;

		void InitializeComponents(Ptr<demos::IControlViewModel> ViewModel)
		{
			ViewModel_ = ViewModel;
			if (InitializeFromResource())
			{
				GUI_INSTANCE_REFERENCE(textBox1);
				GUI_INSTANCE_REFERENCE(textBox2);
				GUI_INSTANCE_REFERENCE(textBox3);
				GUI_INSTANCE_REFERENCE(textBox4);
			}
			else
			{
				ViewModel_ = 0;
			}
		}
	public:
		CalculatorControl_()
			:vl::presentation::GuiInstancePartialClass<vl::presentation::controls::GuiCustomControl>(L"demos::CalculatorControl")
			,vl::presentation::controls::GuiCustomControl(vl::presentation::theme::GetCurrentTheme()->CreateCustomControlStyle())
			,textBox1(0)
			,textBox2(0)
			,textBox3(0)
			,textBox4(0)
		{
		}

		Ptr<demos::IControlViewModel> GetViewModel()
		{
			return ViewModel_;
		}
	};

	template<typename TImpl>
	class MainWindow_ : public vl::presentation::controls::GuiWindow, public vl::presentation::GuiInstancePartialClass<vl::presentation::controls::GuiWindow>, public vl::reflection::Description<TImpl>
	{
		friend struct vl::reflection::description::CustomTypeDescriptorSelector<TImpl>;
	private:
		Ptr<demos::IWindowViewModel> ViewModel_;
	protected:
		demos::CalculatorControl* calculator;

		void InitializeComponents(Ptr<demos::IWindowViewModel> ViewModel)
		{
			ViewModel_ = ViewModel;
			if (InitializeFromResource())
			{
				GUI_INSTANCE_REFERENCE(calculator);
			}
			else
			{
				ViewModel_ = 0;
			}
		}
	public:
		MainWindow_()
			:vl::presentation::GuiInstancePartialClass<vl::presentation::controls::GuiWindow>(L"demos::MainWindow")
			,vl::presentation::controls::GuiWindow(vl::presentation::theme::GetCurrentTheme()->CreateWindowStyle())
			,calculator(0)
		{
		}

		Ptr<demos::IWindowViewModel> GetViewModel()
		{
			return ViewModel_;
		}
	};

}
namespace vl
{
	namespace reflection
	{
		namespace description
		{
			DECL_TYPE_INFO(demos::IControlViewModel)
			DECL_TYPE_INFO(demos::IWindowViewModel)
			DECL_TYPE_INFO(demos::CalculatorControl)
			DECL_TYPE_INFO(demos::MainWindow)

		}
	}
}

#endif
