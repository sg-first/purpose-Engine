purpose Engine
=========
This is a value-driven game event engine. Through it, you can quickly create multi-agent open world and simple game AI.

Quick start
=========
* Define the `property` and` relationship` attributes owned by the Agent.
* Use `class Event` to define an event that triggers when an agent's attribute value satisfies a certain condition (this event typically contains changes to certain Agent and world attribute values). During the polling process, each Agent triggers an event whose condition is satisfied. You can also poll an agent individually. These triggered events will change the state value (you can use `LazyChunk` to delay this process) and being written to` epool`.
* Use the `class EventResponse` to uniquely define the static response function for events in` epool` for all agents. This function can only modify the state inside the agent. This modification can not delay triggering.
* Batch initialization `class Agent` object and give it the initial state! Polling! Run your open world!