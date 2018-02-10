BUILD_DIR = cmocka_build
SOURCE_DIR = cmocka_source

cmocka : $(BUILD_DIR) $(SOURCE_DIR)
	if [ -d $(BUILD_DIR) ]; then :; else mkdir $(BUILD_DIR); fi
	cd $(BUILD_DIR) && cmake ../$(SOURCE_DIR) && make;
	cp $(SOURCE_DIR)/include/cmocka.h .
	cp $(BUILD_DIR)/src/libcmocka* .
	touch cmocka

clean :
	rm libcmocka.so*
	rm cmocka.h
	rm -rf $(BUILD_DIR)
