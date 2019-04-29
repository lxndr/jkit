int main (int argn, char** argv)
{
	try {
		FileStream stm(argv[1]);

		Json::Reader reader(stm);
		auto root_node = reader.rootNode();

		Json::Writer writer;
		writer.setRootNode(root_node);

		writer.toString();
	} catch (Exception& e) {
		StandardStream::error();
	}

	return 0;
}
