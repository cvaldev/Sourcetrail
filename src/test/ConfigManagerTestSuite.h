#include "cxxtest/TestSuite.h"

#include "utility/ConfigManager.h"
#include "utility/text/TextAccess.h"

class ConfigManagerTestSuite: public CxxTest::TestSuite
{
public:
	void test_config_manager_returns_true_when_key_is_found()
	{
		std::shared_ptr<ConfigManager> config = ConfigManager::createAndLoad(getConfigTextAccess());

		float value;
		bool success = config->getValue("path/to/single_value", value);

		TS_ASSERT(success);
	}


	void test_config_manager_returns_false_when_key_is_not_found()
	{
		std::shared_ptr<ConfigManager> config = ConfigManager::createAndLoad(getConfigTextAccess());

		float value;
		bool success = config->getValue("path/to/nowhere", value);

		TS_ASSERT(!success);
	}


	void test_config_manager_returns_correct_string_for_key()
	{
		std::shared_ptr<ConfigManager> config = ConfigManager::createAndLoad(getConfigTextAccess());

		std::string value;
		config->getValue("path/to/single_value", value);

		TS_ASSERT_EQUALS("42", value);
	}


	void test_config_manager_returns_correct_float_for_key()
	{
		std::shared_ptr<ConfigManager> config = ConfigManager::createAndLoad(getConfigTextAccess());

		float value;
		config->getValue("path/to/single_value", value);

		TS_ASSERT_DELTA(42.0f, value, 0.0001f);
	}

	void test_config_manager_returns_correct_bool_for_key_if_value_is_true()
	{
		std::shared_ptr<ConfigManager> config = ConfigManager::createAndLoad(getConfigTextAccess());

		float value;
		bool success(config->getValue("path/to/bool_that_is_true", value));

		TS_ASSERT(success);
		TS_ASSERT(value);
	}

	void test_config_manager_returns_correct_bool_for_key_if_value_is_false()
	{
		std::shared_ptr<ConfigManager> config = ConfigManager::createAndLoad(getConfigTextAccess());

		float value;
		bool success(config->getValue("path/to/bool_that_is_false", value));

		TS_ASSERT(success);
		TS_ASSERT(!value);
	}

private:
	std::shared_ptr<TextAccess> getConfigTextAccess()
	{
		std::string text =
			"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
			"<config>\n"
				"<path>\n"
					"<to>\n"
						"<single_value>42</single_value>\n"
							"<bool_that_is_true>1</bool_that_is_true>\n"
						"<bool_that_is_false>0</bool_that_is_false>\n"
					"</to>\n"
				"</path>\n"
			"</config>\n";

		return TextAccess::createFromString(text);
	}
};
