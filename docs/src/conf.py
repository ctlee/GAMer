# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('/Users/ctlee/gamer/build/lib/'))

import pygamer

# -- Project information -----------------------------------------------------

project = 'GAMer'
copyright = '2019, Christopher T. Lee'
author = 'Christopher T. Lee'

version = '2.0.1'
release = version

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
'sphinx.ext.autosummary',
'sphinx.ext.napoleon',
'sphinx.ext.intersphinx',
'sphinx_issues'
]

# Github repo
issues_github_path = 'ctlee/gamer'

if(True):
    extensions.extend(['breathe', 'exhale'])

# -- Configuration for breathe -----------------------------------------------
breathe_projects = { "gamer_project": "/Users/ctlee/gamer/docs/src/_doxyoutput/xml" }
breathe_default_project = "gamer_project"

# -- Configuration for exhale ------------------------------------------------
exhale_args = {
    "containmentFolder":     "/Users/ctlee/gamer/docs/src/_cppapi",
    "rootFileName":          "root.rst",
    "rootFileTitle":         "C++ API Reference",
    "doxygenStripFromPath":  "/Users/ctlee/gamer",
    "pageLevelConfigMeta":   ":github_url: https://github.com/ctlee/gamer",
    "createTreeView":        True,
    "exhaleExecutesDoxygen": True,
    "exhaleDoxygenStdin":    "INPUT = /Users/ctlee/gamer/include"
}


autosummary_generate = True

# Napoleon settings
napoleon_google_docstring = True
napoleon_numpy_docstring = True
napoleon_include_init_with_doc = True
napoleon_include_private_with_doc = False
napoleon_include_special_with_doc = True
napoleon_use_admonition_for_examples = False
napoleon_use_admonition_for_notes = True
napoleon_use_admonition_for_references = False
napoleon_use_ivar = False
napoleon_use_param = True
napoleon_use_rtype = True

# If true, '()' will be appended to :func: etc. cross-reference text.
add_function_parentheses = True

# If true, sectionauthor and moduleauthor directives will be shown in the
# output. They are ignored by default.
show_authors = True

# Add any paths that contain templates here, relative to this directory.
templates_path = ['/Users/ctlee/gamer/docs/src/_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store', '_templates']

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['/Users/ctlee/gamer/docs/src/_static']

html_context = {
    'css_files': [
        '_static/theme_overrides.css',  # override wide tables in RTD theme
        ],
     }

# Example configuration for intersphinx: refer to the Python standard library.
intersphinx_mapping = {'https://docs.python.org/': None}
