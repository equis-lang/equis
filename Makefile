.PHONY: build install clean test
PREFIX ?= $(HOME)/.equis

build: bootstrap
	@echo "Equis Build Complete"

PG_INC_DIR := $(shell pg_config --includedir 2>/dev/null)
PG_LIB_DIR := $(shell pg_config --libdir 2>/dev/null)
HAS_LIBPQ := $(shell test -f $(PG_INC_DIR)/libpq-fe.h && echo 1 || echo 0)
CFLAGS := -O3
LIBS := -lpthread

ifeq ($(HAS_LIBPQ),1)
    CFLAGS += -I$(PG_INC_DIR) -DUSE_PGSQL
    LIBS += -L$(PG_LIB_DIR) -lpq
endif

eq-core:
	gcc $(CFLAGS) bootstrap.c $(LIBS) -o eq-core
	./eq-core -I std compiler/main.equis > compiler/main.ll
	clang $(CFLAGS) -Wno-override-module compiler/main.ll compiler/runtime.c $(LIBS) -o eq-core

bootstrap: eq-core
	@echo "Bootstrap successful"

check: eq-core
	./eq-core -I std examples/main.equis > check_test.ll
	clang -O3 -Wno-override-module check_test.ll compiler/runtime.c -lpthread -o check_bin
	./check_bin
	@rm check_test.ll check_bin

install: bootstrap
	install -d $(PREFIX)/bin
	install -d $(PREFIX)/lib
	install -m 755 eq $(PREFIX)/bin/eq
	install -m 755 epm $(PREFIX)/bin/epm
	install -m 644 eq.ps1 $(PREFIX)/bin/eq.ps1
	install -m 644 eq.bat $(PREFIX)/bin/eq.bat
	install -m 644 epm.ps1 $(PREFIX)/bin/epm.ps1
	install -m 644 epm.bat $(PREFIX)/bin/epm.bat
	install -m 755 eq-core $(PREFIX)/lib/eq-core
	install -m 644 compiler/runtime.c $(PREFIX)/lib/runtime.c
	cp -r std $(PREFIX)/lib/
	@echo "Equis installed to $(PREFIX)"
	@echo "To use 'eq' globally, ensure $(PREFIX)/bin is in your PATH."

path:
	@echo 'export PATH="$$PATH:$(PREFIX)/bin"' >> $(HOME)/.bashrc
	@echo "Added $(PREFIX)/bin to ~/.bashrc"
	@echo "Please run: source ~/.bashrc"

clean:
	rm -f eq-core compiler/main.ll
	rm -f compiler/main compiler/main_debug
	find . -type f \( -name "*.o" -o -name "*.s" -o -name "*.log" -o -name "*.err" \) -not -path "*/.git/*" -delete

test: install
	$(PREFIX)/bin/eq version
