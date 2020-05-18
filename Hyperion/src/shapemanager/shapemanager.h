#pragma once
#include "api.h"
#include "shape/shape.h"
#include <vector>

namespace Hyperion {
	class GameObject;

	/// <summary>
	/// Holds and managed the shapes on the CPU.
	/// </summary>
	class HPR_API ShapeManager {
	private:
		/// <summary>
		/// The shapes themselves.
		/// </summary>
		ShapeData shapes;

		/// <summary>
		/// A queue which stores the index to every shape that needs to be updated on the next update.
		/// </summary>
		std::vector<unsigned int> queue;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="ShapeManager"/> class.
		/// </summary>
		ShapeManager();

		~ShapeManager();

		/// <summary>
		/// Adds an index of a shape to the queue of the shapes that need to be updated on the next update.
		/// </summary>
		/// <param name="index">The index.</param>
		void addQueue(unsigned int index);

		/// <summary>
		/// Gets the shapes.
		/// </summary>
		/// <returns>The Shapes.</returns>
		ShapeData* getShapes();

		/// <summary>
		/// Allocates a place for a new shape and returns it.
		/// </summary>
		/// <returns>The newly allocted shape.</returns>
		GameObject addShape();

		void removeShape(GameObject go);

		/// <summary>
		/// Gets the queue.
		/// </summary>
		/// <returns>The Queue.</returns>
		std::vector<unsigned int>* getQueue();

		/// <summary>
		/// Clears the queue.
		/// </summary>
		void clearQueue();
	};
}