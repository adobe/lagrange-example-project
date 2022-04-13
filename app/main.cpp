/*
 * Copyright 2022 Adobe
 * All Rights Reserved.
 *
 * NOTICE: Adobe permits you to use, modify, and distribute this file in
 * accordance with the terms of the Adobe license agreement accompanying
 * it.
 */
// If possible, move your code to your library, so that it can be re-used more easily
// and you are sure to avoid UI or other application-specific dependencies.
// Basically, create your library, and be your own client.
#include <foo/foo.h>

// Third-party include
#include <lagrange/Mesh.h>
#include <lagrange/create_mesh.h>
#include <lagrange/io/load_mesh.h>
#include <lagrange/ui/UI.h>
#include <CLI/CLI.hpp>

// System include
#include <iostream>

namespace ui = lagrange::ui;

int main(int argc, char const* argv[])
{
    struct
    {
        std::string input;
    } args;

    CLI::App app{argv[0]};
    app.option_defaults()->always_capture_default();
    app.add_option("input", args.input, "Input mesh.");
    CLI11_PARSE(app, argc, argv);

    std::cout << "Hello world!" << std::endl;

    ui::Viewer viewer("Hello world!", 800, 600);
    if (!viewer.is_initialized()) return 1;

    auto& r = viewer.registry();

    ui::Entity mesh_entity = ui::NullEntity;

    if (args.input.empty()) {
        // you can create meshes and import in UI
        std::shared_ptr<lagrange::TriangleMesh3D> mesh = lagrange::create_sphere();
        mesh_entity = ui::register_mesh(r, mesh);

    } else if (true) {
        // you can load meshes and load into the UI. This will only load geometry, and discard
        // things like material information.
        std::shared_ptr<lagrange::TriangleMesh3D> mesh =
            lagrange::io::load_mesh<lagrange::TriangleMesh3D>(args.input);
        mesh_entity = ui::register_mesh(r, mesh);

    } else {
        // or you can use the ui loader
        mesh_entity = ui::load_obj<lagrange::TriangleMesh3D>(r, args.input);
        // if you have LAGRANGE_WITH_ASSIMP enabled, you can also use ui::load_scene
    }

    // Add mesh to the scene
    ui::show_mesh(r, mesh_entity);

    // Adjust camera to show the entire mesh, regardless of it's original size
    ui::camera_focus_and_fit(r, ui::get_focused_camera_entity(r));

    viewer.run([](ui::Registry& r) -> bool {
        // main loop code

        return true; // should continue running?
    });

    return 0;
}
